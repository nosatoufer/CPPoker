#ifndef MENUCREATEROOM_H
#define MENUCREATEROOM_H

#include <QDialog>
#include <QMessageBox>

using namespace std;

namespace Ui {
class MenuCreateRoom;
}

class MenuCreateRoom : public QDialog
{
    Q_OBJECT

public:
    explicit MenuCreateRoom(QWidget *parent = 0);
    ~MenuCreateRoom();
    string getRoomName();

private slots:
    void slotCreate();
    void slotAnnuler();

private:
    Ui::MenuCreateRoom *ui;
    string nameRoom = "";
};

#endif // MENUCREATEROOM_H
