#ifndef POKERWIDGET_H
#define POKERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include "playerwidget.h"

using namespace std;

class PokerWidget : public QWidget{
private:
    QVector<QLabel*> cards;
    QVector<PlayerWidget*> playerWidget;
    QPushButton * buttonBet = nullptr;
    QPushButton * buttonCheck = nullptr;
    QPushButton * buttonAllIn = nullptr;
    QPushButton * buttonFold = nullptr;
    const int NB_MAX_CARDS = 5;
    const int NB_MAX_PLAYER = 6;

public:
    PokerWidget();
    ~PokerWidget();

    /**
     * @brief getButtonBet returns the ButtonBet
     * @return the ButtonBet
     */
    QPushButton * getButtonBet();

    /**
     * @brief getButtonCheck returns the ButtonCheck
     * @return the ButtonCheck
     */
    QPushButton * getButtonCheck();

    /**
     * @brief getButtonAllIn returns the ButtonAllIn
     * @return the ButtonAllIn
     */
    QPushButton * getButtonAllIn();

    /**
     * @brief getButtonFold returns the ButtonFold
     * @return the ButtonFold
     */
    QPushButton * getButtonFold();

    /**
     * @brief giveCard give a card to the player
     * @param card
     */
    void giveCard(QString card);

    /**
     * @brief addCard adds a card to the table
     * @param card the cards to add
     */
    void addCard(QString card);

    /**
     * @brief deleteAllCards delete all the cards on the table
     */
    void deleteAllCards();

    /**
     * @brief addPlayer adds a player to the table
     * @param namePlayer the player name
     * @param money the money he has
     */
    void addPlayer(QString namePlayer, float money);

    /**
     * @brief deleteAllPlayers delete all the players on the table
     */
    void deleteAllPlayers();

    /**
     * @brief getPlayerWidget returns the player of the given index
     * @param index the index of the player
     * @return the playerwidget
     */
    PlayerWidget * getPlayerWidget(int index);
};

#endif // POKERWIDGET_H
