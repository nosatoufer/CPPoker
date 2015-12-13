#include <QPixmap>

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

    this->buttonCheck = new QPushButton("Check", this);
    this->buttonCheck->resize(100, 30);
    this->buttonCheck->move(295, 550);

    this->buttonCall = new QPushButton("Call", this);
    this->buttonCall->resize(100, 30);
    this->buttonCall->move(405, 550);

    this->buttonRaise = new QPushButton("Raise", this);
    this->buttonRaise->resize(100, 30);
    this->buttonRaise->move(510, 550);

    //Exemple de gestion des cartes
    this->addCard(":/img/cards/2_of_clubs.png");
    this->deleteAllCards();
    this->addCard(":/img/cards/2_of_clubs.png");
    this->addCard(":/img/cards/2_of_clubs.png");
    this->addCard(":/img/cards/2_of_clubs.png");
    this->addCard(":/img/cards/2_of_clubs.png");


    //playerWidget.push_back(new PlayerWidget(this));

    /*for (int i = 0; i < 6; i++) {
        this->playerWidget[i] = new PlayerWidget(this);
        this->cards[i]->resize(68,100);
        this->cards[i]->setPixmap(imgCard.scaled(68,100,Qt::KeepAspectRatio));
    }*/
}

/**
 * @brief PokerWidget::~PokerWidget Destructeur du widget
 */
PokerWidget::~PokerWidget(){
    delete this->buttonFold;
    delete this->buttonCheck;
    delete this->buttonCall;
    delete this->buttonRaise;
    this->deleteAllCards();
    /*for (int i = 0; i < 6; i++) {
        delete this->playerWidget[i];
    }*/
}

/**
 * @brief PokerWidget::getButtonRaise Accesseur du bouton "Raise"
 * @return Bouton "Raise"
 */
QPushButton * PokerWidget::getButtonRaise()
{
    return this->buttonRaise;
}

/**
 * @brief PokerWidget::getButtonCall Accesseur du bouton "Call"
 * @return Bouton "Call"
 */
QPushButton * PokerWidget::getButtonCall()
{
    return this->buttonCall;
}

/**
 * @brief PokerWidget::getButtonCheck Accesseur du bouton "Check"
 * @return Bouton "Check"
 */
QPushButton * PokerWidget::getButtonCheck()
{
    return this->buttonCheck;
}

/**
 * @brief PokerWidget::getButtonFold Accesseur du bouton "Fold"
 * @return Bouton "Fold"
 */
QPushButton * PokerWidget::getButtonFold()
{
    return this->buttonFold;
}

void PokerWidget::addCard(string pathCardFile)
{
    if (this->cards.size() >= 5) return;
    QPixmap imgCard(QString::fromStdString(pathCardFile));
    int index = this->cards.size();
    this->cards.push_back(new QLabel(this));
    this->cards[index]->resize(68,100);
    this->cards[index]->setPixmap(imgCard.scaled(68,100,Qt::KeepAspectRatio));
    switch (index) {
        case 0:
            this->cards[index]->move(244 - (this->cards[index]->size().width()/2), 190);
            break;
        case 1:
            this->cards[index]->move(322 - (this->cards[index]->size().width()/2), 190);
            break;
        case 2:
            this->cards[index]->move(400 - (this->cards[index]->size().width()/2), 190);
            break;
        case 3:
            this->cards[index]->move(478 - (this->cards[index]->size().width()/2), 190);
            break;
        case 4:
            this->cards[index]->move(556 - (this->cards[index]->size().width()/2), 190);
            break;
    }
}

void PokerWidget::deleteAllCards()
{
    for (int i = 0; i < (int)this->cards.size(); i++)
    {
        delete this->cards[i];
        this->cards[i] = nullptr;
    }
    this->cards.clear();
}
