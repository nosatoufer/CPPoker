#ifndef CLIENTSOCK_H
#define CLIENTSOCK_H

#include <QTcpSocket>
#include <QObject>
#include <QDebug>

#include "request.h"
#include "../controller/controller.h"

class Controller;

class ClientSock : public QObject
{
    Q_OBJECT
private:
    QTcpSocket * m_sock;
    Controller* controller;
    std::vector<Request *> m_requests;
    std::string nickname;
    bool identified;
public:
    explicit ClientSock(QString ip, int port, QString nickname, Controller* controller, QObject * parent = 0);

    void write(Request req);
    bool hasRequests();
    Request * getRequest();
    bool isConnected();
    bool isIdentified();
    std::string getNickname();
public slots:
    void connected();
    void read();
    void disconnected();
};

#endif // CLIENTSOCK_H
