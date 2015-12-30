#include "menuchooseroom.h"
#include "ui_menuchooseroom.h"

MenuChooseRoom::MenuChooseRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuChooseRoom)
{
    ui->setupUi(this);

    ui->tableRooms->addItem(QString("Name1"));
    ui->tableRooms->addItem(QString("Name2"));
    ui->tableRooms->addItem(QString("Name3"));
    ui->tableRooms->addItem(QString("Name4"));
    ui->tableRooms->addItem(QString("Name5"));
    ui->tableRooms->item(0)->setSelected(true);

    connect(ui->buttonCancel, SIGNAL(clicked()), this, SLOT(slotAnnuler()));
    connect(ui->buttonConnexion, SIGNAL(clicked()), this, SLOT(slotConnexion()));
}

MenuChooseRoom::~MenuChooseRoom()
{
    delete ui;
}

void MenuChooseRoom::slotConnexion(){
    if(ui->tableRooms->selectedItems().size() == 1){
        QMessageBox::warning(this, ui->tableRooms->selectedItems()[0]->text(), ui->tableRooms->selectedItems()[0]->text());
        this->indexRoom = ui->tableRooms->selectedItems()[0]->text().toInt();
        this->close();
    }
}

void MenuChooseRoom::slotAnnuler(){
    this->close();
}

string MenuChooseRoom::getNameRoom(){
    return this->indexRoom;
}
