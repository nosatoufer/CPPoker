#include "menucreateroom.h"
#include "ui_menucreateroom.h"

MenuCreateRoom::MenuCreateRoom(Controller* controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuCreateRoom),
    controller(controller)
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
    if(ui->nameLineEdit->text() == "") {
        QMessageBox::warning(this, "Erreur !", "Vous devez indiquer le nom de table à créer !");
    } else {
        this->controller->createRoom(ui->nameLineEdit->text().toStdString(),
                                     ui->minPlayerSpinBox->value(),
                                     ui->maxPlayerSpinBox->value(),
                                     ui->smallBlindSpinBox->value(),
                                     ui->bigBlindSpinBox->value());
        this->close();
    }
}

void MenuCreateRoom::slotAnnuler()
{
    this->close();
}
