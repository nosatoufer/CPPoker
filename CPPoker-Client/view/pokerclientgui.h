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
    explicit PokerClientGui(Controller* m_controller, QWidget *parent = 0);
    ~PokerClientGui();

    void displayRooms(std::map<std::string, std::string> rooms);

    void displayErrorMessage(QString message);
    void displaySuccessMessage(QString message);

    void startGame();

    void addPlayer(QString player);
    void remPlayer(QString player);

public slots:
    void bet(int value);
    void fold();
    void allIn();

private slots:
    void slotQuitter();
    void slotConnexion();
    void slotNouveauSalon();
    void slotDeconnexion();
    void slotApropos();
    void slotRegles();
    void slotCombinaison();
    void slotStartGame();

private:
    Ui::PokerClientGui *ui;
    PokerWidget * pokerwidget = nullptr;
    Controller * m_controller;
    QString playerName;
    QVector<QString> m_players;
    QString addressIP;
    int port;
    bool isConnected = false;
};

#endif // POKERCLIENTGUI_H
