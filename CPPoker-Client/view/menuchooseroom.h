#ifndef MENUCHOOSEROOM_H
#define MENUCHOOSEROOM_H

#include <QDialog>
#include <QVector>
#include <QStandardItemModel>
#include <QMessageBox>
#include "../controller/controller.h"
#include "../network/utils.h"

using namespace std;


namespace Ui {
class MenuChooseRoom;
}

/**
 * @brief The MenuChooseRoom class allows the user to create or to join a room
 */
class MenuChooseRoom : public QDialog
{
    Q_OBJECT

public:
    explicit MenuChooseRoom(std::map<std::string, std::string> rooms, Controller* m_controller, QWidget *parent = 0);
    ~MenuChooseRoom();

    /**
     * @brief getNameRoom returns the room's name
     * @return the romm's name
     */
    string getNameRoom();

private slots:
    /**
     * @brief slotConnexion tries to join the selected room
     */
    void slotConnexion();
    /**
     * @brief slotAnnuler closes the window
     */
    void slotAnnuler();
    /**
     * @brief slotCreateTable closes the window
     */
    void slotCreateTable();

private:
    Ui::MenuChooseRoom *ui;
    string m_indexRoom = "";
    Controller* m_controller;
    QVector<std::string> m_roomsName;
};

#endif // MENUCHOOSEROOM_H
