#ifndef CONTROLER_H
#define CONTROLER_H
#include "network/clientsock.h"

class Controler
{
private:
    ClientSock * m_socket;
public:
    Controler();

    /**
     * @brief setSocket initialise the socket
     * @param ip the ip to connect to
     * @param port the port to connect to
     */
    void setSocket(QString ip, int port);

    /**
     * @brief askNickname ask if the chosen nickname is available
     * @param nickname the chosen nickname
     */
    void askNickname(QString nickname);

    /**
     * @brief fold tell to the server the player folds
     */
    void fold();

    /**
     * @brief allIn tell to the server the player wants toput all in
     */
    void allIn();

    /**
     * @brief check tell to the server the player checks
     */
    void check();

    /**
     * @brief call tell to the server the player wants to check
     */
    void call();

    /**
     * @brief raise tell to the server th player wants to raise
     * @param raise the amout to raise
     */
    void raise(int raise);

    bool connectTo(QString ip, int port);

private:

    void readRequest();
};

#endif // CONTROLER_H
