#include "clientsock.h"

ClientSock::ClientSock(QString ip, int port, QString nickname, Controller* controller, QObject *parent) :
    QObject(parent),
    m_controller(controller),
    m_requests(),
    m_nickname(nickname.toStdString()),
    m_identified(false)
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
    {
        qDebug() << "Request received : " << req;
        m_requests.insert(m_requests.begin(), req);
    }
    manageRequest();
}

void ClientSock::manageRequest()
{
    while(m_requests.size() > 0)
    {
        QString req = m_requests.back();
        m_requests.pop_back();
        Request* request = new Request(req.toStdString());
        switch (request->getCommand()) {
        case LOGIN:
            if (request->isSet(Request::STATUS)) {
                if (request->getStatus() == Request::STATUS_FAILURE) {
                    qDebug() << "LOGIN_3";
                    m_controller->nicknameUsed();
                    m_identified = false;
                } else {
                    qDebug() << "LOGIN_2";
                    m_controller->nicknameAvailable();
                    m_identified = true;
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
                this->m_controller->displayRooms(request->getMap("rooms"));
            }
            break;

        case ROOM_CREATE:
            qDebug() << "ROOM_CREATE";
            //if (request->getStatus() == Request::STATUS_FAILURE) {
            //this->controller->errorCreateRoom();
            break;

        case GAME_START:
            m_controller->gameStarted();
            break;
        case PLAYER_JOINED:
            m_controller->addPlayer(QString(request->get("pName").c_str()));
            break;

        case POKER_GIVE_CARD:
        {
            std::pair<QString,QString> cards;
            cards.first = QString(request->get("cardOne").c_str());
            cards.second = QString(request->get("cardTwo").c_str());
            m_controller->playerCard(cards);
            break;
        }
        case POKER_SHOW_CARD_TABLE:
            m_controller->showTableCard(QString(request->get("card").c_str()));
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
    s += "|";
    qDebug() << "Write : " << QString::fromStdString(s);
    if(m_sock->isWritable())
        m_sock->write(s.c_str(), s.length());
}

bool ClientSock::hasRequests()
{
    return m_requests.size() != 0;
}



bool ClientSock::isConnected()
{
    return m_sock->isOpen();
}


bool ClientSock::isIdentified()
{
    return m_identified;
}

std::string ClientSock::getNickname() {
    return this->m_nickname;
}
