#ifndef MENUCONNEXION_H
#define MENUCONNEXION_H

#include <QDialog>

namespace Ui {
class MenuConnexion;
}

class MenuConnexion : public QDialog
{
    Q_OBJECT

public:
    explicit MenuConnexion(QWidget *parent = 0);
    ~MenuConnexion();
    QString getPlayerName();
    QString getAddressIP();
    int getPort();

private slots:
    void slotConnexion();
    void slotAnnuler();

private:
    Ui::MenuConnexion *ui;
    QString playerName;
    QString addressIP;
    int port;

};

#endif // MENUCONNEXION_H
