#include "playerwidget.h"

/**
 * @brief PlayerWidget::PlayerWidget Constructeur du widget représentant un joueur
 * @param parent Widget parent
 * @param name Nom du joueur
 */
PlayerWidget::PlayerWidget(QWidget *parent, string name, float money) : QWidget(parent)
{
    this->layoutPlayerWidget = new QVBoxLayout(this);

    QPixmap imgUser(":/img/user.png");
    QPixmap imgDealer(":/img/dealer.png");
    QPixmap imgSmallBlind(":/img/smallblind.png");
    QPixmap imgBigBlind(":/img/bigblind.png");
    this->imgPlayer = new QLabel();
    this->imgPlayer->resize(65, 100);
    this->imgPlayer->setPixmap(imgUser.scaled(100,100,Qt::KeepAspectRatio));
    this->imgPlayer->setAlignment(Qt::AlignCenter);

    this->labelNamePlayer = new QLabel(QString::fromStdString(name));
    this->labelNamePlayer->setAlignment(Qt::AlignCenter);

    this->labelMoney = new QLabel(QString::number(money) + " €");
    this->labelMoney->setAlignment(Qt::AlignCenter);

    this->layoutPlayerWidget->addWidget(this->imgPlayer);
    this->layoutPlayerWidget->addWidget(this->labelNamePlayer);
    this->layoutPlayerWidget->addWidget(this->labelMoney);

    QFont fontLabelNamePlayer;
    fontLabelNamePlayer.setBold(true);
    this->labelNamePlayer->setFont(fontLabelNamePlayer);

    this->widgetPions = new QWidget();
    this->layoutPions = new QHBoxLayout();
    this->layoutPions->setAlignment(Qt::AlignCenter);

    this->labelDealer = new QLabel();
    this->labelDealer->setPixmap(imgDealer.scaled(35,35,Qt::KeepAspectRatio));
    this->labelDealer->setVisible(false);
    this->labelSmallBlind = new QLabel();
    this->labelSmallBlind->setPixmap(imgSmallBlind.scaled(35,35,Qt::KeepAspectRatio));
    this->labelSmallBlind->setVisible(false);
    this->labelBigBlind = new QLabel();
    this->labelBigBlind->setPixmap(imgBigBlind.scaled(35,35,Qt::KeepAspectRatio));
    this->labelBigBlind->setVisible(false);

    this->layoutPions->addWidget(this->labelDealer);
    this->layoutPions->addWidget(this->labelSmallBlind);
    this->layoutPions->addWidget(this->labelBigBlind);
    this->widgetPions->setLayout(this->layoutPions);
    this->layoutPlayerWidget->addWidget(this->widgetPions);
}

/**
 * @brief PlayerWidget::~PlayerWidget Destructeur du widget
 */
PlayerWidget::~PlayerWidget()
{
    delete this->labelNamePlayer;
    delete this->imgPlayer;
    delete this->layoutPlayerWidget;
    delete this->labelMoney;
    delete this->layoutPions;
    delete this->labelDealer;
    delete this->labelSmallBlind;
    delete this->labelBigBlind;
    delete this->widgetPions;
}

/**
 * @brief PlayerWidget::getNamePlayer Accesseur du contenu du QLabel contenant le nom du joueur
 * @return Nom du joueur
 */
string PlayerWidget::getNamePlayer()
{
    return this->labelNamePlayer->text().toStdString();
}

/**
 * @brief PlayerWidget::setNamePlayer Mutateur du contenu du QLabel contenant le nom du joueur
 * @param newNamePlayer
 */
void PlayerWidget::setNamePlayer(string newNamePlayer)
{
    this->labelNamePlayer->setText(QString::fromStdString(newNamePlayer));
}

void PlayerWidget::setVisiblePionDealer(bool visible)
{
    this->labelDealer->setVisible(visible);
}

void PlayerWidget::setVisiblePionSmallBlind(bool visible)
{
    this->labelSmallBlind->setVisible(visible);
}

void PlayerWidget::setVisiblePionBigBlind(bool visible)
{
    this->labelBigBlind->setVisible(visible);
}
