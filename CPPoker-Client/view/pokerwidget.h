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
    QPushButton * buttonRaise = nullptr;
    QPushButton * buttonCall = nullptr;
    QPushButton * buttonCheck = nullptr;
    QPushButton * buttonFold = nullptr;
    const int NB_MAX_CARDS = 5;
    const int NB_MAX_PLAYER = 6;

public:
    PokerWidget();
    ~PokerWidget();
    QPushButton * getButtonRaise();
    QPushButton * getButtonCall();
    QPushButton * getButtonCheck();
    QPushButton * getButtonFold();
    void addCard(string pathCardFile);
    void deleteAllCards();
    void addPlayer(string namePlayer, float money);
    void deleteAllPlayers();
    PlayerWidget * getPlayerWidget(int index);
};

#endif // POKERWIDGET_H
