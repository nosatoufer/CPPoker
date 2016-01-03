#include "clientsock.h"

ClientSock::ClientSock(QString ip, int port, QString nickname, Controller* controller, QObject *parent) :
    QObject(parent),
    controller(controller),
    m_requests(),
    nickname(nickname.toStdString()),
    identified(false)
{
    m_sock = new QTcpSocket();
    connect(m_sock, SIGNAL(connected()), this, SLOT(connected()));
    connect(m_sock, SIGNAL(readyRead()), this, SLOT(read()));
    connect(m_sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    m_sock->connectToHost(ip, port);
}

void ClientSock::connected()
{
    qDebug() << "Connected";
}

void ClientSock::read()
{
    QRegExp rex("[|]");
    QString s(m_sock->readAll());
    QStringList requests = s.split(rex, QString::SkipEmptyParts);
    for(QString req : requests)
        m_requests.insert(m_requests.begin(), req);

    manageRequest();
}

void ClientSock::manageRequest()
{
    while(m_requests.size() > 0)
    {
        QString req = m_requests.back();
        m_requests.pop_back();
        qDebug() << req;
        Request* request = new Request(req.toStdString());
        switch (request->getCommand()) {
        case LOGIN:
            if (request->isSet(Request::STATUS)) {
                if (request->getStatus() == Request::STATUS_FAILURE) {
                    qDebug() << "LOGIN_3";
                    controller->nicknameUsed();
                    identified = false;
                } else {
                    qDebug() << "LOGIN_2";
                    controller->nicknameAvailable();
                    identified = true;
                }
            } else {
                qDebug() << "LOGIN_1";
                request->set("pName", this->getNickname());
                this->write(request->toString());
            }
            break;

        case ROOM_LIST:
            qDebug() << "ROOM_LIST";
            if (request->getStatus() == Request::STATUS_FAILURE) {
                // A gérer
            } else {
                qDebug() << "Call display rooms";
                this->controller->displayRooms(request->getMap("rooms"));
            }
            break;

        case ROOM_CREATE:
            qDebug() << "ROOM_CREATE";
            //if (request->getStatus() == Request::STATUS_FAILURE) {
            //this->controller->errorCreateRoom();
            break;

        case GAME_START:
            controller->gameStarted();
            break;
        case PLAYER_JOINED:
            controller->addPlayer(QString(request->get("pName").c_str()));
            break;

        case POKER_GIVE_CARD:
        {
            std::pair<QString,QString> cards;
            cards.first = QString(request->get("cardOne").c_str());
            cards.second = QString(request->get("cardTwo").c_str());
            controller->playerCard(cards);
            break;
        }
        case POKER_SHOW_CARD_TABLE:
            controller->showTableCard(QString(request->get("card").c_str()));
            break;
        default:
            qDebug() << "Unknown command";
            break;
        }
        delete request;
    }
}

void ClientSock::disconnected()
{
    qDebug() << "Disconnected";
}

void ClientSock::write(Request req)
{
    std::string s = req.toString();
    qDebug() << "Write : " << QString::fromStdString(s);
    if(m_sock->isWritable())
        m_sock->write(s.c_str(), s.length());
}

bool ClientSock::hasRequests()
{
    return m_requests.size() != 0;
}

Request* ClientSock::getRequest()
{

    //Request * c = m_requests.back();
    //m_requests.pop_back();
    //return c;
}

bool ClientSock::isConnected()
{
    return m_sock->isOpen();
}


bool ClientSock::isIdentified()
{
    return identified;
}

std::string ClientSock::getNickname() {
    return this->nickname;
}
