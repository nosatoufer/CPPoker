#include "pokerclientgui.h"
#include "ui_pokerclientgui.h"
#include "menuconnexion.h"
#include "menuchooseroom.h"
#include "menucreateroom.h"

#include <QDebug>


/**
 * @brief PokerClientGui::PokerClientGui Constructeur de la fenêtre principale
 * @param parent
 */
PokerClientGui::PokerClientGui(Controller* controller, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PokerClientGui),
    m_controller(controller)
{
    ui->setupUi(this);

    //Taille de la fenêtre non modifiable
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    //Connexion des boutons aux slots
    connect(ui->actionQuitter, &QAction::triggered, this, &PokerClientGui::slotQuitter);
    connect(ui->actionConnexion, &QAction::triggered, this, &PokerClientGui::slotConnexion);
    connect(ui->actionDeconnexion, &QAction::triggered, this, &PokerClientGui::slotDeconnexion);
    connect(ui->actionApropos, &QAction::triggered, this, &PokerClientGui::slotApropos);
    connect(ui->actionRegles, &QAction::triggered, this, &PokerClientGui::slotRegles);
    connect(ui->actionCombinaisons, &QAction::triggered, this, &PokerClientGui::slotCombinaison);
    connect(ui->actionNouveauSalon, &QAction::triggered, this, &PokerClientGui::slotNouveauSalon);
    connect(ui->actionD_marrer, &QAction::triggered, this, &PokerClientGui::slotStartGame);

    //Affichage de la fenêtre de connexion
    MenuConnexion menuCo(controller);
    menuCo.exec();
}

/**
 * @brief PokerClientGui::~PokerClientGui Destructeur de la fenêtre principale
 */
PokerClientGui::~PokerClientGui()
{
    //Suppresion du widget représentant la table de poker
    if(this->m_pokerwidget != nullptr)
    {
        disconnect(this->m_pokerwidget->getButtonFold(), SIGNAL(clicked()), this, SLOT(fold()));
        disconnect(this->m_pokerwidget->getButtonCheck(), SIGNAL(clicked()), this, SLOT(check()));
        disconnect(this->m_pokerwidget->getButtonAllIn(), SIGNAL(clicked()), this, SLOT(allIn()));
        disconnect(this->m_pokerwidget->getButtonBet(), SIGNAL(clicked()), this, SLOT(bet()));
        delete(this->m_pokerwidget);
        this->m_pokerwidget = nullptr;
    }

    //Suppresion de la fenêtre
    if(this->ui != nullptr)
    {
        delete this->ui;
        this->m_pokerwidget = nullptr;
    }
}

void PokerClientGui::displayErrorMessage(QString message)
{
    QMessageBox::critical(this, "Erreur", message);
}

void PokerClientGui::displaySuccessMessage(QString message)
{
    QMessageBox::information(this, "Bravo", message);
}

void PokerClientGui::startGame()
{
    m_pokerwidget = new PokerWidget();
    for( QString player : m_players)
        m_pokerwidget->addPlayer(player, 1000);
    connect(this->m_pokerwidget->getButtonFold(), SIGNAL(clicked()), this, SLOT(fold()));
    connect(this->m_pokerwidget->getButtonCheck(), SIGNAL(clicked()), this, SLOT(check()));
    connect(this->m_pokerwidget->getButtonAllIn(), SIGNAL(clicked()), this, SLOT(allIn()));
    connect(this->m_pokerwidget->getButtonBet(), SIGNAL(clicked()), this, SLOT(bet()));
    this->setCentralWidget(this->m_pokerwidget);
    this->resize(800, 600);
}

void PokerClientGui::addPlayer(QString player)
{
    qDebug() << "m_players.append()";
    m_players.append(player);
}

void PokerClientGui::remPlayer(QString player)
{
    m_players.removeOne(player);
}

void PokerClientGui::giveCards(std::pair<QString,QString> card)
{
    /*
    int i = 0;
    while(i < m_pokerwidget->size() && m_pokerwidget->at(i++).getName() != m_pName );
    if(i < m_pokerwidget->size() )
    {
        m_pokerwidget->setCard
    }
    */
}

void PokerClientGui::showTableCard(QString card)
{
    m_pokerwidget->addCard(card);
}

void PokerClientGui::bet()
{
    m_controller->bet(1);
}

void PokerClientGui::fold()
{
    m_controller->fold();
}

void PokerClientGui::allIn()
{
    m_controller->allIn();
}

void PokerClientGui::check()
{
    m_controller->check();
}

/**
 * @brief PokerClientGui::slotQuitter Slot du bouton "Quitter"
 */
void PokerClientGui::slotQuitter()
{
    if(this->m_isConnected){
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Quitter ?",
                             "Voulez-vous vraiment quitter le jeu ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            //A COMPLETER !!!
            this->~PokerClientGui();
        }
    }
    else
    {
        this->~PokerClientGui();
    }
}

/**
 * @brief PokerClientGui::slotConnexion Slot du bouton "Connexion"
 */
void PokerClientGui::slotConnexion()
{
    //Vérification si le client est déjà connecté
    qDebug() << "OK 1";
    if(this->m_controller->isConnected())
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,
                "Se connecter sur un autre serveur ?",
                "Voulez-vous vraiment vous connecter sur un autre serveur ? Si oui, votre partie sera interrompu !",
                QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::No)
        {
            return;
        }
    }
    qDebug() << "OK 2";

    //Suppresion de la partie en cours
    this->resize(300, 100);
    if(this->m_pokerwidget != nullptr)
    {
        disconnect(this->m_pokerwidget->getButtonFold(), SIGNAL(clicked()), this, SLOT(fold()));
        disconnect(this->m_pokerwidget->getButtonCheck(), SIGNAL(clicked()), this, SLOT(check()));
        disconnect(this->m_pokerwidget->getButtonAllIn(), SIGNAL(clicked()), this, SLOT(allIn()));
        disconnect(this->m_pokerwidget->getButtonBet(), SIGNAL(clicked()), this, SLOT(bet()));
        this->m_pokerwidget = nullptr;
    }

    //Affichage de la fenêtre de connexion
    MenuConnexion menuCo(m_controller);
    menuCo.exec();

    //Récupération des données
        if(!(menuCo.getPlayerName() == ""))
        {
            this->m_playerName = menuCo.getPlayerName();
            this->m_addressIP = menuCo.getAddressIP();
            this->m_port = menuCo.getPort();
            this->m_isConnected = true;
            this->startGame();
        }
}

void PokerClientGui::displayRooms(std::map<std::string, std::string> rooms) {
    qDebug() << "Call display rooms³";
    MenuChooseRoom menuChooseRoom(rooms, m_controller, this);
    qDebug() << "Call display rooms 4";
    menuChooseRoom.exec();
    /*if(!(menuChooseRoom.getNameRoom() == ""))
    {
        this->playerName = menuCo.getPlayerName();
        this->addressIP = menuCo.getAddressIP();
        this->port = menuCo.getPort();
        this->isConnected = true;
        this->pokerwidget = new PokerWidget();
        this->setCentralWidget(this->pokerwidget);
        connect(this->pokerwidget->getButtonFold(), SIGNAL(clicked()), this, SLOT(slotFold()));
        connect(this->pokerwidget->getButtonCheck(), SIGNAL(clicked()), this, SLOT(slotCheck()));
        connect(this->pokerwidget->getButtonCall(), SIGNAL(clicked()), this, SLOT(slotCall()));
        connect(this->pokerwidget->getButtonRaise(), SIGNAL(clicked()), this, SLOT(slotRaise()));
        this->resize(800, 600);
        this->show();
    } else {
        this->show();
    }*/
}

/**
 * @brief PokerClientGui::slotNouveauSalon Slot du bouton "Nouveau salon"
 */
void PokerClientGui::slotNouveauSalon()
{
    //Vérification si déjà connecté
    if(this->m_isConnected)
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,
                "Se connecter sur un autre serveur ?",
                "Voulez-vous vraiment vous connecter sur un autre serveur ? Si oui, votre partie sera interrompu !",
                QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::No)
        {
            return;
        }
    }

    if(this->m_pokerwidget != nullptr)
    {
        disconnect(this->m_pokerwidget->getButtonFold(), SIGNAL(clicked()), this, SLOT(fold()));
        disconnect(this->m_pokerwidget->getButtonCheck(), SIGNAL(clicked()), this, SLOT(check()));
        disconnect(this->m_pokerwidget->getButtonAllIn(), SIGNAL(clicked()), this, SLOT(allIn()));
        disconnect(this->m_pokerwidget->getButtonBet(), SIGNAL(clicked()), this, SLOT(bet()));
        delete(this->m_pokerwidget);
        this->m_pokerwidget = nullptr;
    }
    this->resize(300, 100);

    MenuCreateRoom menuCreateRoom(m_controller);
    menuCreateRoom.exec();
}

/**
 * @brief PokerClientGui::slotDeconnexion Slot du bouton "Déconnexion"
 */
void PokerClientGui::slotDeconnexion()
{
    if(this->m_isConnected)
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Se déconnecter ?",
                                      "Voulez-vous vraiment vous déconnecter ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            this->m_isConnected = false;
            if(this->m_pokerwidget != nullptr)
            {
                disconnect(this->m_pokerwidget->getButtonFold(), SIGNAL(clicked()), this, SLOT(fold()));
                disconnect(this->m_pokerwidget->getButtonCheck(), SIGNAL(clicked()), this, SLOT(check()));
                disconnect(this->m_pokerwidget->getButtonAllIn(), SIGNAL(clicked()), this, SLOT(allIn()));
                disconnect(this->m_pokerwidget->getButtonBet(), SIGNAL(clicked()), this, SLOT(bet()));
                delete(this->m_pokerwidget);
                this->m_pokerwidget = nullptr;
            }
            this->resize(300, 100);
        }
    }
    else
    {
        QMessageBox::information(this, tr("Déconnexion impossible"), tr("Il n'y a aucune partie en cours !"));
    }
}

/**
 * @brief PokerClientGui::slotApropos Slot du bouton "A propos"
 */
void PokerClientGui::slotApropos()
{
    QMessageBox::information(this, tr("A propos"), tr("A completé"));
}

/**
 * @brief PokerClientGui::slotRegles Slot du bouton "règles"
 */
void PokerClientGui::slotRegles()
{
    QMessageBox::information(this, tr("Règles du jeu"), tr("A completé"));
}

/**
 * @brief PokerClientGui::slotCombinaison Slot du bouton "Combinaison"
 */
void PokerClientGui::slotCombinaison()
{
    QMessageBox::information(this, tr("Combinaisons"), tr("A completé"));
}


void PokerClientGui::slotStartGame()
{
    m_controller->startGame();
}
