#include "pokerwidget.h"

/**
 * @brief PokerWidget::PokerWidget Constructeur du widget représentant la table de poker
 */
PokerWidget::PokerWidget() : QWidget()
{
    //Couleur de fond
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::green);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    //Création des boutons
    this->buttonFold = new QPushButton("Fold", this);
    this->buttonFold->resize(100, 30);
    this->buttonFold->move(190, 550);

    this->buttonAllIn = new QPushButton("AllIN", this);
    this->buttonAllIn->resize(100, 30);
    this->buttonAllIn->move(295, 550);

    this->buttonCheck = new QPushButton("Check", this);
    this->buttonCheck->resize(100, 30);
    this->buttonCheck->move(405, 550);

    this->buttonBet = new QPushButton("Bet", this);
    this->buttonBet->resize(100, 30);
    this->buttonBet->move(510, 550);

    /*
    //Exemple de gestion des cartes
    this->addCard(":/img/cards/2_of_clubs.png");
    this->deleteAllCards();
    this->addCard(":/img/cards/2_of_clubs.png");
    this->addCard(":/img/cards/2_of_clubs.png");
    this->addCard(":/img/cards/2_of_clubs.png");
    this->addCard(":/img/cards/2_of_clubs.png");
    this->addCard(":/img/cards/2_of_clubs.png");

    this->addPlayer("joueur1",0.1);
    this->addPlayer("joueur2",0.);
    this->addPlayer("joueur3",200.);
    this->addPlayer("joueur4",0.);
    this->addPlayer("joueur5",0.);
    this->addPlayer("joueur6",0.);

    this->getPlayerWidget(0)->setVisiblePionDealer(true);
    this->getPlayerWidget(1)->setVisiblePionSmallBlind(true);
    this->getPlayerWidget(2)->setVisiblePionBigBlind(true);
    */
}

/**
 * @brief PokerWidget::~PokerWidget Destructeur du widget
 */
PokerWidget::~PokerWidget(){
    delete this->buttonFold;
    delete this->buttonAllIn;
    delete this->buttonCheck;
    delete this->buttonBet;
    this->deleteAllCards();
    this->deleteAllPlayers();
}

/**
 * @brief PokerWidget::getButtonRaise Accesseur du bouton "Bet"
 * @return Bouton "Raise"
 */
QPushButton * PokerWidget::getButtonBet()
{
    return this->buttonBet;
}

/**
 * @brief PokerWidget::getButtonCall Accesseur du bouton "Check"
 * @return Bouton "Call"
 */
QPushButton * PokerWidget::getButtonCheck()
{
    return this->buttonCheck;
}

/**
 * @brief PokerWidget::getButtonCheck Accesseur du bouton "AllIn"
 * @return Bouton "Check"
 */
QPushButton * PokerWidget::getButtonAllIn()
{
    return this->buttonAllIn;
}

/**
 * @brief PokerWidget::getButtonFold Accesseur du bouton "Fold"
 * @return Bouton "Fold"
 */
QPushButton * PokerWidget::getButtonFold()
{
    return this->buttonFold;
}

void PokerWidget::giveCard(QString card)
{
}

/**
 * @brief PokerWidget::addCard Méthode permettant d'ajouter une carte dans le widget
 * @param pathCardFile Chemin de l'image de la carte
 */
void PokerWidget::addCard(QString card)
{
    if ((int)this->cards.size() >= this->NB_MAX_CARDS) return;
    QPixmap imgCard(":/img/cards/"+card+".png");
    int index = this->cards.size();
    this->cards.push_back(new QLabel(this));
    this->cards[index]->resize(68,100);
    this->cards[index]->setPixmap(imgCard.scaled(68,100,Qt::KeepAspectRatio));
    switch (index) {
        case 0:
            this->cards[index]->move(244 - (this->cards[index]->size().width()/2), 220);
            break;
        case 1:
            this->cards[index]->move(322 - (this->cards[index]->size().width()/2), 220);
            break;
        case 2:
            this->cards[index]->move(400 - (this->cards[index]->size().width()/2), 220);
            break;
        case 3:
            this->cards[index]->move(478 - (this->cards[index]->size().width()/2), 220);
            break;
        case 4:
            this->cards[index]->move(556 - (this->cards[index]->size().width()/2), 220);
            break;
    }
}

/**
 * @brief PokerWidget::deleteAllCards Méthode permettant de supprimer toutes les cartes du widget
 */
void PokerWidget::deleteAllCards()
{
    for (int i = 0; i < (int)this->cards.size(); i++)
    {
        delete this->cards[i];
        this->cards[i] = nullptr;
    }
    this->cards.clear();
}

/**
 * @brief PokerWidget::addPlayer Méthode permettant d'ajouter un nouveau joueur dans le widget
 * @param namePlayer Nom du joueur
 */
void PokerWidget::addPlayer(QString namePlayer, float money)
{
    if ((int)this->playerWidget.size() >= this->NB_MAX_PLAYER) return;
    int index = this->playerWidget.size();
    this->playerWidget.push_back(new PlayerWidget(this, namePlayer, money));
    switch (index) {
        case 0:
            this->playerWidget[index]->move(50, 60);
            break;
        case 1:
            this->playerWidget[index]->move(400 - this->playerWidget[index]->width()/2, 10);
            break;
        case 2:
            this->playerWidget[index]->move(750 - this->playerWidget[index]->width(), 60);
            break;
        case 3:
            this->playerWidget[index]->move(50, 290);
            break;
        case 4:
            this->playerWidget[index]->move(400 - this->playerWidget[index]->width()/2, 340);
            break;
        case 5:
            this->playerWidget[index]->move(750 - this->playerWidget[index]->width(), 290);
            break;
    }
}

/**
 * @brief PokerWidget::deleteAllPlayers Méthode permettant de supprimer tous les joueurs du widget
 */
void PokerWidget::deleteAllPlayers()
{
    for (int i = 0; i < (int)this->playerWidget.size(); i++)
    {
        delete this->playerWidget[i];
        this->playerWidget[i] = nullptr;
    }
    this->playerWidget.clear();
}

PlayerWidget * PokerWidget::getPlayerWidget(int index)
{
    if(index >=0 && index < (int)this->playerWidget.size())
    {
        return this->playerWidget[index];
    }
    else
    {
        return nullptr;
    }
}
