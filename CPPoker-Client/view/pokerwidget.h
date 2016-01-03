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
    vector<QLabel*> cards;
    vector<PlayerWidget*> playerWidget;
    QPushButton * buttonBet = nullptr;
    QPushButton * buttonCheck = nullptr;
    QPushButton * buttonAllIn = nullptr;
    QPushButton * buttonFold = nullptr;
    const int NB_MAX_CARDS = 5;
    const int NB_MAX_PLAYER = 6;

public:
    PokerWidget();
    ~PokerWidget();
    QPushButton * getButtonBet();
    QPushButton * getButtonCheck();
    QPushButton * getButtonAllIn();
    QPushButton * getButtonFold();
    void addCard(QString card);
    void deleteAllCards();
    void addPlayer(QString namePlayer, float money);
    void deleteAllPlayers();
    PlayerWidget * getPlayerWidget(int index);
};

#endif // POKERWIDGET_H
