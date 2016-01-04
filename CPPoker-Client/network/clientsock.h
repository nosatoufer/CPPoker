#ifndef CLIENTSOCK_H
#define CLIENTSOCK_H

#include <QTcpSocket>
#include <QObject>
#include <QDebug>

#include "request.h"
#include "../controller/controller.h"

class Controller;

/**
 * @brief The ClientSock class reads and sends the request through the network
 */
class ClientSock : public QObject
{
    Q_OBJECT
private:
    QTcpSocket * m_sock;
    Controller* m_controller;
    QVector<QString> m_requests;
    std::string m_nickname;
    bool m_identified;
public:
    explicit ClientSock(QString ip, int port, QString m_nickname, Controller* m_controller, QObject * parent = 0);

    /**
     * @brief write writes the given request on the socket
     * @param req the request to write
     */
    void write(Request req);

    /**
     * @brief hasRequests returns if the socket received request or not
     * @return true if the queue contains request
     */
    bool hasRequests();


    /**
     * @brief isConnected return if the socket is connected or not1
     * @return true if the socket is connected
     */
    bool isConnected();

    /**
     * @brief isIdentified
     * @return
     */
    bool isIdentified();

    /**
     * @brief getNickname returns the nickname
     * @return the nickname
     */
    std::string getNickname();

public slots:
    /**
     * @brief connected shows a message when the socket succesfully connect
     */
    void connected();
    /**
     * @brief read reads the socket and queue all the request found.
     */
    void read();

    /**
     * @brief disconnected shows a message when the socket lost the connection
     */
    void disconnected();

private:
    /**
     * @brief manageRequest manages the requests and send the information to the controller if necessary
     */
    void manageRequest();
};

#endif // CLIENTSOCK_H
