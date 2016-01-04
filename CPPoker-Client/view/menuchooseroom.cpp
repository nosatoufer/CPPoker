#include "menuchooseroom.h"
#include "ui_menuchooseroom.h"

MenuChooseRoom::MenuChooseRoom(std::map<std::string, std::string> rooms, Controller* controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuChooseRoom),
    m_roomsName(),
    m_controller(controller)
{
    ui->setupUi(this);

    std::map<std::string, std::string> temp;
    for (std::map<std::string, std::string>::iterator it=rooms.begin(); it!=rooms.end(); ++it) {
        temp = jsonDecode(it->second);
        if (temp.size() > 1) {
            ui->tableRooms->addItem(QString::fromStdString(temp.at("name")
                                    + " - (" + temp.at("currentPlayer") + "/" + temp.at("maxPlayer") + ") "
                                    + " - (" + temp.at("smallBlind") + "/" + temp.at("bigBlind") + ")"));
            m_roomsName.push_back(temp.at("name"));
        }
    }

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
    if(ui->tableRooms->selectedItems().size() == 1) {
        QString name = ui->tableRooms->selectedItems()[0]->text();
        QRegExp rx("[ ]");
        QStringList list = name.split(rx, QString::SkipEmptyParts);
        QMessageBox::warning(this, "Joindre table", list.at(0));
        m_controller->joinRoom(list.at(0));
        this->close();
    }
}

void MenuChooseRoom::slotAnnuler(){
    this->close();
}

void MenuChooseRoom::slotCreateTable(){
    this->close();
}

string MenuChooseRoom::getNameRoom(){
    return this->m_indexRoom;
}
