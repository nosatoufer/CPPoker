#ifndef CLIENTSOCK_H
#define CLIENTSOCK_H

#include <QTcpSocket>
#include <QObject>
#include <QDebug>

#include "request.h"

class clientSock : public QObject
{
    Q_OBJECT
private:
    QTcpSocket * m_sock;
public:
    explicit clientSock(QObject * parent = 0);

    void askNickname(QString nickname);
public slots:
    void connected();
    void read();
};

#endif // CLIENTSOCK_H
