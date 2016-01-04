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
    /**
     * @brief getRoomName returns the room's name
     * @return the room's name
     */
    string getRoomName();

private slots:
    /**
     * @brief slotCreate tries to create a room
     */
    void slotCreate();
    /**
     * @brief slotAnnuler cancels the room creation
     */
    void slotAnnuler();

private:
    Ui::MenuCreateRoom *ui;
    string nameRoom = "";
    Controller* controller;
};

#endif // MENUCREATEROOM_H
