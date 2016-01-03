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

class PokerClientGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit PokerClientGui(Controller* controller, QWidget *parent = 0);
    ~PokerClientGui();

    void displayRooms(std::map<std::string, std::string> rooms);

    void displayErrorMessage(QString message);
    void displaySuccessMessage(QString message);

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
    Controller * controller;
    QString playerName;
    QString addressIP;
    int port;
    bool isConnected = false;
};

#endif // POKERCLIENTGUI_H
