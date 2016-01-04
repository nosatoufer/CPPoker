#ifndef POKERCLIENTGUI_H
#define POKERCLIENTGUI_H

#include <QMainWindow>
#include <QMessageBox>
#include "pokerwidget.h"
#include "controller/controller.h"

namespace Ui {
class PokerClientGui;
}
class Controller;

/**
 * @brief The PokerClientGui class
 */
class PokerClientGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit PokerClientGui(Controller* m_controller, QWidget *parent = 0);
    ~PokerClientGui();

    /**
     * @brief displayRooms displays a windows containing the rooms given
     * @param rooms the list of rooms
     */
    void displayRooms(std::map<std::string, std::string> rooms);

    /**
     * @brief displayErrorMessage displays an error message
     * @param message the error message
     */
    void displayErrorMessage(QString message);

    /**
     * @brief displaySuccessMessage diplays a success message
     * @param message the success message
     */
    void displaySuccessMessage(QString message);

    /**
     * @brief startGame diplay the table
     */
    void startGame();

    /**
     * @brief addPlayer add a player
     * @param player the player name
     */
    void addPlayer(QString player);

    /**
     * @brief remPlayer removes a player
     * @param player the player name
     */
    void remPlayer(QString player);

    /**
     * @brief giveCards give two cards to a player
     * @param pName the player to give the card to
     * @param card the two cards
     */
    void giveCards(QString pName, std::pair<QString, QString> card);

    /**
     * @brief showTableCard adds a card to the table
     * @param card the card to add
     */
    void showTableCard(QString card);

public slots:
    /**
     * @brief bet asks the controller to send a request "bet"
     */
    void bet();
    /**
     * @brief bet asks the controller to send a request "bet"
     */
    void fold();
    /**
     * @brief fold asks the controller to send a request "fold"
     */
    void allIn();
    /**
     * @brief allIn asks the controller to send a request "allIn"
     */
    void check();
    /**
     * @brief check asks the controller to send a request "check"
     */

private slots:
    /**
     * @brief slotQuitter closes the window
     */
    void slotQuitter();
    /**
     * @brief slotConnexion allows the client to disconnect and connect to an other server
     */
    void slotConnexion();

    /**
     * @brief slotNouveauSalon allows the client to asks to create a new room
     */
    void slotNouveauSalon();

    /**
     * @brief slotDeconnexion disconnects from the current server
     */
    void slotDeconnexion();

    /**
     * @brief slotApropos TODO displays the about
     */
    void slotApropos();
    /**
     * @brief slotRegles TODO displays the rules
     */
    void slotRegles();
    /**
     * @brief slotCombinaison TODO display the hands value
     */
    void slotCombinaison();
    /**
     * @brief slotStartGame asks the server to start the game
     */
    void slotStartGame();

private:
    Ui::PokerClientGui *ui;
    PokerWidget * m_pokerwidget = nullptr;
    Controller * m_controller;
    QString m_playerName;
    QVector<QString> m_players;
    QString m_addressIP;
    int m_port;
    bool m_isConnected = false;
    QString m_pName;
};

#endif // POKERCLIENTGUI_H
