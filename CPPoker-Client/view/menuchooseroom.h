#ifndef MENUCHOOSEROOM_H
#define MENUCHOOSEROOM_H

#include <QDialog>
#include <QStandardItemModel>
#include <QMessageBox>
#include "../controller/controller.h"
#include "../network/utils.h"

using namespace std;

namespace Ui {
class MenuChooseRoom;
}

class MenuChooseRoom : public QDialog
{
    Q_OBJECT

public:
    explicit MenuChooseRoom(std::map<std::string, std::string> rooms, Controller* controller, QWidget *parent = 0);
    ~MenuChooseRoom();
    string getNameRoom();

private slots:
    void slotConnexion();
    void slotAnnuler();
    void slotCreateTable();

private:
    Ui::MenuChooseRoom *ui;
    string indexRoom = "";
    Controller* controller;
    std::vector<std::string> roomsName;
};

#endif // MENUCHOOSEROOM_H
