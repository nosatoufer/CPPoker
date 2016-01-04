#include "pokerwidget.h"
#include <QDebug>

PokerWidget::PokerWidget() : QWidget()
{
    //Couleur de fond
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::darkGreen);
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

}

PokerWidget::~PokerWidget(){
    delete this->buttonFold;
    delete this->buttonAllIn;
    delete this->buttonCheck;
    delete this->buttonBet;
    this->deleteAllCards();
    this->deleteAllPlayers();
}


QPushButton * PokerWidget::getButtonBet()
{
    return this->buttonBet;
}

QPushButton * PokerWidget::getButtonCheck()
{
    return this->buttonCheck;
}

QPushButton * PokerWidget::getButtonAllIn()
{
    return this->buttonAllIn;
}

QPushButton * PokerWidget::getButtonFold()
{
    return this->buttonFold;
}

void PokerWidget::giveCard(QString card)
{
    //playerWidget.at(0)->
}

void PokerWidget::addCard(QString card)
{
    qDebug() << card;
    if ((int)this->cards.size() >= this->NB_MAX_CARDS) return;
    QPixmap imgCard(":/img/cards/"+card+".png");
    int index = this->cards.size();
    this->cards.append(new QLabel(this));
    this->cards.at(index)->resize(68,100);
    this->cards.at(index)->setPixmap(imgCard.scaled(68,100,Qt::KeepAspectRatio));
    switch (index) {
        case 0:
            this->cards.at(index)->move(244 - (this->cards.at(index)->size().width()/2), 220);
            break;
        case 1:
            this->cards.at(index)->move(322 - (this->cards.at(index)->size().width()/2), 220);
            break;
        case 2:
            this->cards.at(index)->move(400 - (this->cards.at(index)->size().width()/2), 220);
            break;
        case 3:
            this->cards.at(index)->move(478 - (this->cards.at(index)->size().width()/2), 220);
            break;
        case 4:
            this->cards.at(index)->move(556 - (this->cards.at(index)->size().width()/2), 220);
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
        delete this->cards.at(i);
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
    qDebug() << "AddPlayer" << namePlayer;
    if ((int)this->playerWidget.size() >= this->NB_MAX_PLAYER) return;
    int index = this->playerWidget.size();
    this->playerWidget.append(new PlayerWidget(this, namePlayer, money));
    switch (index) {
        case 0:
            this->playerWidget.at(index)->move(50, 60);
            break;
        case 1:
            this->playerWidget.at(index)->move(400 - this->playerWidget.at(index)->width()/2, 10);
            break;
        case 2:
            this->playerWidget.at(index)->move(750 - this->playerWidget.at(index)->width(), 60);
            break;
        case 3:
            this->playerWidget.at(index)->move(50, 290);
            break;
        case 4:
            this->playerWidget.at(index)->move(400 - this->playerWidget.at(index)->width()/2, 340);
            break;
        case 5:
            this->playerWidget.at(index)->move(750 - this->playerWidget.at(index)->width(), 290);
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
        delete this->playerWidget.at(i);
        this->playerWidget[i] = nullptr;
    }
    this->playerWidget.clear();
}

PlayerWidget * PokerWidget::getPlayerWidget(int index)
{
    if(index >=0 && index < (int)this->playerWidget.size())
    {
        return this->playerWidget.at(index);
    }
    else
    {
        return nullptr;
    }
}
