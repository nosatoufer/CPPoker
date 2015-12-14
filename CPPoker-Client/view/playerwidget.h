#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <string>
#include <QVBoxLayout>

using namespace std;

class PlayerWidget : public QWidget{

private:
    QLabel * imgPlayer;
    QLabel * labelNamePlayer;
    QVBoxLayout * layoutPlayerWidget;

public:
    PlayerWidget(QWidget * parent, string name);
    ~PlayerWidget();
    string getNamePlayer();
    void setNamePlayer(string newNamePlayer);
};

#endif // PLAYERWIDGET_H
