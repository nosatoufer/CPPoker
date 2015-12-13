/*#include "clientsock.h"

clientSock::clientSock(QObject *parent) :
    QObject(parent)
{
    m_sock = new QTcpSocket();
    connect(m_sock, SIGNAL(connected()), this, SLOT(connected()));
    connect(m_sock, SIGNAL(readyRead()), this, SLOT(read()));

    m_sock->connectToHost("127.0.0.1",  1234);

}

void clientSock::connected()
{
    qDebug() << "Connected";

}

void clientSock::read()
{
    qDebug() << m_sock->readAll();
}

*/
