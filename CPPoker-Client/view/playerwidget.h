#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QVBoxLayout>
#include <QLabel>
#include <string>
#include "pokerwidget.h"

using namespace std;

class PlayerWidget : public QWidget
{

private:
    QLabel * imgPlayer;
    QLabel * labelNamePlayer;

public:
    /*PlayerWidget(PokerWidget * parent, string name);
    string getNamePlayer();
    void setNamePlayer(string newNamePlayer);*/
};

#endif // PLAYERWIDGET_H
