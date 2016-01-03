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

/**
 * @brief The PokerClientGui class
 */
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
    void giveCards(QString card);
    void showTableCard(QString card);

public slots:
    void bet();
    void fold();
    void allIn();
    void check();

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
    PokerWidget * m_pokerwidget = nullptr;
    Controller * m_controller;
    QString m_playerName;
    QVector<QString> m_players;
    QString m_addressIP;
    int m_port;
    bool m_isConnected = false;
    QString m_pName;
};

#endif // POKERCLIENTGUI_H
