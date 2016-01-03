#include "menuchooseroom.h"
#include "ui_menuchooseroom.h"

MenuChooseRoom::MenuChooseRoom(std::map<std::string, std::string> rooms, Controller* controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuChooseRoom),
    roomsName(),
    controller(controller)
{
    //qDebug() << "MenuChooseRoom";
    ui->setupUi(this);

    //qDebug() << "MenuChooseRoom 1";
    std::map<std::string, std::string> temp;
    for (std::map<std::string, std::string>::iterator it=rooms.begin(); it!=rooms.end(); ++it) {
        temp = jsonDecode(it->second);
        if (temp.size() > 1) {
            ui->tableRooms->addItem(QString::fromStdString(temp.at("name") + " - (" + temp.at("currentPlayer") + "/" + temp.at("maxPlayer") + ") "
                                    + " - (" + temp.at("smallBlind") + "/" + temp.at("bigBlind") + ")"));
            roomsName.push_back(temp.at("name"));
        }
    }
    //qDebug() << "MenuChooseRoom 3";

    connect(ui->buttonCancel, SIGNAL(clicked()), this, SLOT(slotAnnuler()));
    connect(ui->buttonConnexion, SIGNAL(clicked()), this, SLOT(slotConnexion()));
    connect(ui->buttonCreate, SIGNAL(clicked()), this, SLOT(slotAnnuler()));
    connect(ui->buttonCreate, SIGNAL(clicked()), parent, SLOT(slotNouveauSalon()));
}

MenuChooseRoom::~MenuChooseRoom()
{
    delete ui;
}

void MenuChooseRoom::slotConnexion(){
    /*
    if(ui->tableRooms->selectedItems().size() == 1){
        QMessageBox::warning(this, ui->tableRooms->selectedItems()[0]->text(), ui->tableRooms->selectedItems()[0]->text());
        this->indexRoom = ui->tableRooms->selectedItems()[0]->text().toInt();
        this->close();
    }
    TODO : GERER LA CONNEXION A LA TABLE
    controller->joinRoom(TABLE_NAME);
    */
}

void MenuChooseRoom::slotAnnuler(){
    this->close();
}

void MenuChooseRoom::slotCreateTable(){
    this->close();
}

string MenuChooseRoom::getNameRoom(){
    return this->indexRoom;
}
