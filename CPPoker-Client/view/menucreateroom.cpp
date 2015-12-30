#include "menucreateroom.h"
#include "ui_menucreateroom.h"

MenuCreateRoom::MenuCreateRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuCreateRoom)
{
    ui->setupUi(this);

    connect(ui->buttonCreate, SIGNAL(clicked()), this, SLOT(slotCreate()));
    connect(ui->buttonCancel, SIGNAL(clicked()), this, SLOT(slotAnnuler()));
}

MenuCreateRoom::~MenuCreateRoom()
{
    delete ui;
}

string MenuCreateRoom::getRoomName()
{
    return this->nameRoom;
}

void MenuCreateRoom::slotCreate()
{
    if(ui->nameRoom->text() == ""){
        QMessageBox::warning(this, "Erreur !", "Vous devez indiquer le nom de table à créer !");
    }else{
        this->nameRoom = ui->nameRoom->text().toStdString();
        this->close();
    }
}

void MenuCreateRoom::slotAnnuler()
{
    this->close();
}
