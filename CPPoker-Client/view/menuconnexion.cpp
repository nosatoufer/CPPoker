#include "menuconnexion.h"
#include "ui_menuconnexion.h"

#include <QMessageBox>


MenuConnexion::MenuConnexion(Controller* controller, QWidget *parent) :
    controller(controller),
    ui(new Ui::MenuConnexion),
    QDialog(parent)
{
    ui->setupUi(this);

    //Taille de la fenêtre non modifiable
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    //Connexion des boutons
    connect(ui->buttonAnnuler, SIGNAL(clicked()), this, SLOT(slotAnnuler()));
    connect(ui->buttonConnexion, SIGNAL(clicked()), this, SLOT(slotConnexion()));
}


MenuConnexion::~MenuConnexion()
{
    delete ui;
}


void MenuConnexion::slotConnexion()
{
    //Vérification si les champs ne sont pas vide
    if(ui->lineEditNamePlayer->text().isEmpty() || ui->lineEditIPAddress->text().isEmpty()
            || ui->lineEditPort->text().isEmpty()){
        QMessageBox::warning(this, tr("Champ vide !"), tr("Un des champ du formulaire n'est pas rempli"));
        return;
    }

    //Vérification de l'adresse IP
    QStringList splits = ui->lineEditIPAddress->text().split(".");
    std::string tmp;
    if(splits.size() != 4)
    {
        QMessageBox::warning(this, tr("Adresse IP invalide !"), tr("L'adresse IP est invalide !"));
        return;
    }
    for(int i = 0; i < splits.size(); i++)
    {
        //Vérification si l'adresse IP contient que des nombres
        tmp = splits[i].toStdString();
        for(int j = 0; j < (int)tmp.size(); j++)
        {
            if(tmp[j] < '0' || tmp[j] > '9')
            {
                QMessageBox::warning(this, tr("Adresse IP invalide !"), tr("L'adresse IP est invalide !"));
                return;
            }
        }

        //Vérification de chaque nombre de l'adresse IP
        if(splits[i].toInt() < 0 || splits[i].toInt() > 255)
        {
            QMessageBox::warning(this, tr("Adresse IP invalide !"), tr("L'adresse IP est invalide !"));
            return;
        }
    }

    //Vérification du port
    for(int i = 0; i < ui->lineEditPort->text().size(); i++)
    {
        if(ui->lineEditPort->text()[i] < '0' || ui->lineEditPort->text()[i] > '9')
        {
            QMessageBox::warning(this, tr("Port invalide !"),
                                 tr("Le numéro de port est doit être compris entre 0 et 65536 !"));
            return;
        }
    }
    if(ui->lineEditPort->text().toInt() < 0 || ui->lineEditPort->text().toInt() > 65536)
    {
        QMessageBox::warning(this, tr("Port invalide !"),
                             tr("Le numéro de port est doit être compris entre 0 et 65536 !"));
        return;
    }

    //Traitement des données
    this->playerName = ui->lineEditNamePlayer->text();
    this->addressIP = ui->lineEditIPAddress->text();
    this->port = ui->lineEditPort->text().toInt();
    if(controller->connectTo(this->addressIP, this->port, this->playerName))
        this->close();
    else
        QMessageBox::warning(this, tr("Connexion échouée !"), tr("Impossible de se connecter !"));}


void MenuConnexion::slotAnnuler()
{
    this->close();
}


QString MenuConnexion::getPlayerName()
{
    return this->playerName;
}

QString MenuConnexion::getAddressIP()
{
    return this->addressIP;
}


int MenuConnexion::getPort()
{
    return this->port;
}
