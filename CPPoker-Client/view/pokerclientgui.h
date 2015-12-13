#ifndef POKERCLIENTGUI_H
#define POKERCLIENTGUI_H

#include <QMainWindow>

#include "pokerwidget.h"

namespace Ui {
class PokerClientGui;
}

class PokerClientGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit PokerClientGui(QWidget *parent = 0);
    ~PokerClientGui();

private slots:
    void slotQuitter();
    void slotConnexion();
    void slotNouveauSalon();
    void slotDeconnexion();
    void slotApropos();
    void slotRegles();
    void slotCombinaison();
    void slotCheck();
    void slotFold();
    void slotCall();
    void slotRaise();

private:
    Ui::PokerClientGui *ui;
    PokerWidget * pokerwidget = nullptr;
    QString playerName;
    QString addressIP;
    int port;
    bool isConnected = false;
};

#endif // POKERCLIENTGUI_H
