#ifndef MENUCREATEROOM_H
#define MENUCREATEROOM_H

#include <QDialog>
#include <QMessageBox>
#include "controller/controller.h"

using namespace std;

namespace Ui {
class MenuCreateRoom;
}

class MenuCreateRoom : public QDialog
{
    Q_OBJECT

public:
    explicit MenuCreateRoom(Controller* controller, QWidget *parent = 0);
    ~MenuCreateRoom();
    string getRoomName();

private slots:
    void slotCreate();
    void slotAnnuler();

private:
    Ui::MenuCreateRoom *ui;
    string nameRoom = "";
    Controller* controller;
};

#endif // MENUCREATEROOM_H
