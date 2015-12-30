#include "clientsock.h"

ClientSock::ClientSock(QString ip, int port, QString nickname, QObject *parent) :
    QObject(parent)
{
    m_sock = new QTcpSocket();
    connect(m_sock, SIGNAL(connected()), this, SLOT(connected()));
    connect(m_sock, SIGNAL(readyRead()), this, SLOT(read()));
    connect(m_sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    this->nickname = nickname.toStdString();
    m_sock->connectToHost(ip,  port);
}

void ClientSock::connected()
{
    qDebug() << "Connected";

}

void ClientSock::read()
{
    //m_requests.insert(m_requests.begin(), new Request(m_sock->readAll().toStdString()));
    Request request((QString(m_sock->readAll())).toStdString());
    switch (request.getCommand()) {
        case LOGIN:
            if (request.isSet(Request::STATUS)) {
                if (request.getStatus() == Request::STATUS_FAILURE) {
                    qDebug() << "LOGIN_3";
                } else {
                    qDebug() << "LOGIN_2";
                }
            } else {
                qDebug() << "LOGIN_1";
                request.set("nickname",this->nickname);
                this->write(request.toString());
            }
        break;
        default:
            qDebug() << "Unknown command";
        break;
    }
}

void ClientSock::disconnected()
{
    qDebug() << "Disconnected";
}



void ClientSock::write(Request req)
{
    std::string s = req.toString();
    if(m_sock->isWritable())
        m_sock->write(s.c_str(), s.length());
}

bool ClientSock::hasRequests()
{
    return m_requests.size() != 0;
}

Request *ClientSock::getRequest()
{
    Request * c = m_requests.back();
    m_requests.pop_back();
    return c;
}

bool ClientSock::isConnected()
{
    return m_sock->isOpen();
}
