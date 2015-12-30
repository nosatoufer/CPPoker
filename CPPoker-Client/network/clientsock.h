#ifndef CLIENTSOCK_H
#define CLIENTSOCK_H

#include <QTcpSocket>
#include <QObject>
#include <QDebug>

#include "request.h"

class ClientSock : public QObject
{
    Q_OBJECT
private:
    QTcpSocket * m_sock;
    std::vector<Request *> m_requests;
public:
    explicit ClientSock(QString ip = "127.0.0.1", int port = 1234, QObject * parent = 0);

    /**
     * @brief write convert a request and write it on the socket
     * @param req the request to write
     */
    void write(Request req);
    bool hasRequests();
    Request * getRequest();
    bool isConnected();
public slots:
    void connected();
    void read();
    void disconnected();
};

#endif // CLIENTSOCK_H
