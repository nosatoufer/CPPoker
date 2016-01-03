#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <string>
#include <QVBoxLayout>
#include <QHBoxLayout>

using namespace std;

class PlayerWidget : public QWidget{

private:
    QLabel * imgPlayer;
    QLabel * labelNamePlayer;
    QVBoxLayout * layoutPlayerWidget;
    float money;
    QLabel * labelMoney;
    QWidget * widgetPions;
    QHBoxLayout * layoutPions;
    QLabel * labelDealer;
    QLabel * labelSmallBlind;
    QLabel * labelBigBlind;

public:
    PlayerWidget(QWidget * parent, QString name, float money);
    ~PlayerWidget();
    string getNamePlayer();
    void setNamePlayer(string newNamePlayer);
    void setVisiblePionDealer(bool visible);
    void setVisiblePionSmallBlind(bool visible);
    void setVisiblePionBigBlind(bool visible);
};

#endif // PLAYERWIDGET_H
