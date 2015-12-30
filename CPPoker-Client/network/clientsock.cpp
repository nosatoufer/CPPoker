#include "clientsock.h"

ClientSock::ClientSock(QString ip, int port, QObject *parent) :
    QObject(parent)
{
    m_sock = new QTcpSocket();
    connect(m_sock, SIGNAL(connected()), this, SLOT(connected()));
    connect(m_sock, SIGNAL(readyRead()), this, SLOT(read()));
    connect(m_sock, SIGNAL(disconnected()), this, SLOT(disconnected()));

    m_sock->connectToHost(ip,  port);
}

void ClientSock::connected()
{
    qDebug() << "Connected";

}

void ClientSock::read()
{
    m_requests.insert(m_requests.begin(), new Request(m_sock->readAll().toStdString()));
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
