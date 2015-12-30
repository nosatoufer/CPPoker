#ifndef MENUCHOOSEROOM_H
#define MENUCHOOSEROOM_H

#include <QDialog>
#include <QStandardItemModel>
#include <QMessageBox>

using namespace std;

namespace Ui {
class MenuChooseRoom;
}

class MenuChooseRoom : public QDialog
{
    Q_OBJECT

public:
    explicit MenuChooseRoom(QWidget *parent = 0);
    ~MenuChooseRoom();
    string getNameRoom();

private slots:
    void slotConnexion();
    void slotAnnuler();

private:
    Ui::MenuChooseRoom *ui;
    string indexRoom = "";
};

#endif // MENUCHOOSEROOM_H
