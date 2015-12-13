#ifndef POKERWIDGET_H
#define POKERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <view/playerwidget.h>

using namespace std;

class PokerWidget : public QWidget{
private:
    vector<QLabel*> cards;
    //vector<PlayerWidget*> playerWidget;
    QPushButton * buttonRaise = nullptr;
    QPushButton * buttonCall = nullptr;
    QPushButton * buttonCheck = nullptr;
    QPushButton * buttonFold = nullptr;

public:
    PokerWidget();
    ~PokerWidget();
    QPushButton * getButtonRaise();
    QPushButton * getButtonCall();
    QPushButton * getButtonCheck();
    QPushButton * getButtonFold();
    void addCard(string pathCardFile);
    void deleteAllCards();
};

#endif // POKERWIDGET_H
