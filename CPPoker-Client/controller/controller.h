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
    ClientSock* m_socket;
    PokerClientGui* m_view;
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

    /**
     * @brief playerCard gives to the view the pair of cards in the player's and
     * @param cards the two cards in the player's hand
     */
    void playerCard(std::pair<QString, QString> cards);

    /**
     * @brief showTableCard shows the next card to display on the table
     * @param card the card to display
     */
    void showTableCard(QString card);

    /**
     * @brief isIdentified
     * @return
     */
    bool isIdentified();

    /**
     * @brief nicknameUsed
     */
    void nicknameUsed();

    /**
     * @brief nicknameAvailable display a window the show the player has succesfully joined the server and ask the list of rooms
     */
    void nicknameAvailable();

    /**
     * @brief askRooms asks the list of rooms
     */
    void askRooms();

    /**
     * @brief joinRoom asks the server to join the room of the given name
     * @param name the name of the room to join
     */
    void joinRoom(QString name);

    /**
     * @brief displayRooms send the map of rooms to display to the view
     * @param rooms the maps of rooms
     */
    void displayRooms(std::map<std::string, std::string> rooms);

    /**
     * @brief attachView attaches a view to the controller
     * @param view the view to attach
     */
    void attachView(PokerClientGui* m_view);

    /**
     * @brief attachSocket attaches a socket to the controller
     * @param socket the socket to attach
     */
    void attachSocket(ClientSock* m_socket);

    /**
     * @brief createRoom asks the server to create a room of the given information
     * @param name the name of the room
     * @param minPlayer the minimum amout of player to start the game
     * @param maxPlayer the maximum amount of player allowed in the room
     * @param smallBlind the small blind
     * @param bigBlind the big blind
     */
    void createRoom(std::string name, unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind);

    /**
     * @brief startGame asks the server to start the game
     */
    void startGame();

    /**
     * @brief gameStarted warns the view the game has started
     */
    void gameStarted();

    /**
     * @brief addPlayer warns the view a player has joined the game
     * @param pName the player name who joined
     */
    void addPlayer(QString pName);

private:
    /**
     * @brief readRequest reads all the requets in the stack of request.
     */
    void readRequest();
};

#endif // CONTROLER_H
