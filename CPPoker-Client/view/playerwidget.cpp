#include "playerwidget.h"

/**
 * @brief PlayerWidget::PlayerWidget Constructeur du widget représentant un joueur
 * @param parent Widget parent
 * @param name Nom du joueur
 */
PlayerWidget::PlayerWidget(QWidget *parent, string name) : QWidget(parent)
{
    this->layoutPlayerWidget = new QVBoxLayout(this);

    QPixmap imgUser(":/img/user.png");
    this->imgPlayer = new QLabel();
    this->imgPlayer->resize(65, 100);
    this->imgPlayer->setPixmap(imgUser.scaled(100,100,Qt::KeepAspectRatio));

    this->labelNamePlayer = new QLabel(QString::fromStdString(name));

    this->layoutPlayerWidget->addWidget(this->imgPlayer);
    this->layoutPlayerWidget->addWidget(this->labelNamePlayer);
}

/**
 * @brief PlayerWidget::~PlayerWidget Destructeur du widget
 */
PlayerWidget::~PlayerWidget()
{
    delete this->labelNamePlayer;
    delete this->imgPlayer;
    delete this->layoutPlayerWidget;
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
