/********************************************************************************
** Form generated from reading UI file 'menuconnexion.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUCONNEXION_H
#define UI_MENUCONNEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MenuConnexion
{
public:
    QGridLayout *gridLayout;
    QLabel *labelNamePlayer;
    QLineEdit *lineEditNamePlayer;
    QLabel *labelIPAddress;
    QLineEdit *lineEditIPAddress;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QPushButton *buttonConnexion;
    QPushButton *buttonAnnuler;

    void setupUi(QDialog *MenuConnexion)
    {
        if (MenuConnexion->objectName().isEmpty())
            MenuConnexion->setObjectName(QStringLiteral("MenuConnexion"));
        MenuConnexion->resize(241, 151);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/connexion.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuConnexion->setWindowIcon(icon);
        gridLayout = new QGridLayout(MenuConnexion);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelNamePlayer = new QLabel(MenuConnexion);
        labelNamePlayer->setObjectName(QStringLiteral("labelNamePlayer"));

        gridLayout->addWidget(labelNamePlayer, 0, 0, 1, 1);

        lineEditNamePlayer = new QLineEdit(MenuConnexion);
        lineEditNamePlayer->setObjectName(QStringLiteral("lineEditNamePlayer"));

        gridLayout->addWidget(lineEditNamePlayer, 0, 1, 1, 2);

        labelIPAddress = new QLabel(MenuConnexion);
        labelIPAddress->setObjectName(QStringLiteral("labelIPAddress"));

        gridLayout->addWidget(labelIPAddress, 1, 0, 1, 1);

        lineEditIPAddress = new QLineEdit(MenuConnexion);
        lineEditIPAddress->setObjectName(QStringLiteral("lineEditIPAddress"));

        gridLayout->addWidget(lineEditIPAddress, 1, 1, 1, 2);

        labelPort = new QLabel(MenuConnexion);
        labelPort->setObjectName(QStringLiteral("labelPort"));

        gridLayout->addWidget(labelPort, 2, 0, 1, 1);

        lineEditPort = new QLineEdit(MenuConnexion);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 2, 1, 1, 2);

        buttonConnexion = new QPushButton(MenuConnexion);
        buttonConnexion->setObjectName(QStringLiteral("buttonConnexion"));

        gridLayout->addWidget(buttonConnexion, 3, 0, 1, 2);

        buttonAnnuler = new QPushButton(MenuConnexion);
        buttonAnnuler->setObjectName(QStringLiteral("buttonAnnuler"));

        gridLayout->addWidget(buttonAnnuler, 3, 2, 1, 1);

        QWidget::setTabOrder(lineEditNamePlayer, lineEditIPAddress);
        QWidget::setTabOrder(lineEditIPAddress, lineEditPort);
        QWidget::setTabOrder(lineEditPort, buttonConnexion);
        QWidget::setTabOrder(buttonConnexion, buttonAnnuler);

        retranslateUi(MenuConnexion);

        QMetaObject::connectSlotsByName(MenuConnexion);
    } // setupUi

    void retranslateUi(QDialog *MenuConnexion)
    {
        MenuConnexion->setWindowTitle(QApplication::translate("MenuConnexion", "Connexion", 0));
        labelNamePlayer->setText(QApplication::translate("MenuConnexion", "Nom du joueur :", 0));
        labelIPAddress->setText(QApplication::translate("MenuConnexion", "Adresse IP :", 0));
        lineEditIPAddress->setText(QApplication::translate("MenuConnexion", "127.0.0.1", 0));
        labelPort->setText(QApplication::translate("MenuConnexion", "Port :", 0));
        lineEditPort->setText(QApplication::translate("MenuConnexion", "1234", 0));
        buttonConnexion->setText(QApplication::translate("MenuConnexion", "Connexion", 0));
        buttonAnnuler->setText(QApplication::translate("MenuConnexion", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class MenuConnexion: public Ui_MenuConnexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUCONNEXION_H
