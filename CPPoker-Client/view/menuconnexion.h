#ifndef MENUCONNEXION_H
#define MENUCONNEXION_H

#include <QDialog>

#include "controller/controller.h"

namespace Ui {
class MenuConnexion;
}

class MenuConnexion : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief MenuConnexion Constructeur de la fenêtre de connexion
     * @param parent
     */
    explicit MenuConnexion(Controller * controller, QWidget *parent = 0);

    /**
     * @brief ~MenuConnexion Destructeur de la fenêtre de connexion
     */
    ~MenuConnexion();

    /**
     * @brief getPlayerName Accesseur du nom du joueur
     * @return Nom du joueur
     */
    QString getPlayerName();


    /**
     * @brief getAddressIP Accesseur de l'adresse IP du serveur
     * @return Adresse IP du serveur
     */
    QString getAddressIP();

    /**
     * @brief getPort Accesseur du port
     * @return Port
     */
    int getPort();

private slots:
    /**
     * @brief slotConnexion slot du bouton "Connexion"
     */
    void slotConnexion();
    /**
     * @brief slotAnnuler Slot du bouton "Annuler"
     */
    void slotAnnuler();

private:
    Controller* controller;
    Ui::MenuConnexion *ui;
    QString playerName;
    QString addressIP;
    int port;

};

#endif // MENUCONNEXION_H
