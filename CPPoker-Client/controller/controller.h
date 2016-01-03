#ifndef CONTROLER_H
#define CONTROLER_H
#include "../network/clientsock.h"
#include "../view/pokerclientgui.h"

class PokerClientGui;
class ClientSock;

/**
 * @brief The Controller class manages the communication between the ClientSocket and View
 */
class Controller
{
private:
    ClientSock* socket;
    PokerClientGui* view;
public:
    Controller();

    virtual ~Controller();

    /**
     * @brief setSocket initializes the socket
     * @param ip the ip to connect to
     * @param port the port to connect to
     */
    void setSocket(QString ip, int port);

    /**
     * @brief askNickname asks if the chosen nickname is available
     * @param nickname the chosen nickname
     */
    void askNickname(QString nickname);

    /**
     * @brief fold tells to the server the player folds
     */
    void fold();

    /**
     * @brief allIn tells to the server the player wants toput all in
     */
    void allIn();

    /**
     * @brief check tells to the server the player checks
     */
    void check();

    /**
     * @brief call tells to the server the player wants to check
     */
    void call();

    /**
     * @brief bet tells to the server the player wants to bet the given amout
     * @param value the amout to bet
     */
    void bet(int value);

    /**
     * @brief connectTo
     * @param ip
     * @param port
     * @return
     */
    bool connectTo(QString ip, int port, QString nickname);

    /**
     * @brief isConnected
     * @return
     */
    bool isConnected();

    void playerCard(std::pair<QString, QString> cards);

    void showTableCard(QString card);

    bool isIdentified();

    void nicknameUsed();

    void nicknameAvailable();

    void askRooms();

    void joinRoom(QString name);

    void displayRooms(std::map<std::string, std::string> rooms);

    void attachView(PokerClientGui* view);

    void attachModel(ClientSock* socket);

    void createRoom(std::string name, unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind);

    void startGame();

    void gameStarted();

    void addPlayer(QString pName);

private:
    void readRequest();
};

#endif // CONTROLER_H
