/********************************************************************************
** Form generated from reading UI file 'menuconnexion.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MenuConnexion
{
public:
    QLabel *labelNamePlayer;
    QLabel *labelIPAddress;
    QLabel *labelPort;
    QPushButton *buttonConnexion;
    QPushButton *buttonAnnuler;
    QLineEdit *lineEditPort;
    QLineEdit *lineEditNamePlayer;
    QLineEdit *lineEditIPAddress;

    void setupUi(QDialog *MenuConnexion)
    {
        if (MenuConnexion->objectName().isEmpty())
            MenuConnexion->setObjectName(QStringLiteral("MenuConnexion"));
        MenuConnexion->resize(241, 151);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/connexion.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuConnexion->setWindowIcon(icon);
        labelNamePlayer = new QLabel(MenuConnexion);
        labelNamePlayer->setObjectName(QStringLiteral("labelNamePlayer"));
        labelNamePlayer->setGeometry(QRect(20, 20, 80, 20));
        labelIPAddress = new QLabel(MenuConnexion);
        labelIPAddress->setObjectName(QStringLiteral("labelIPAddress"));
        labelIPAddress->setGeometry(QRect(20, 50, 80, 20));
        labelPort = new QLabel(MenuConnexion);
        labelPort->setObjectName(QStringLiteral("labelPort"));
        labelPort->setGeometry(QRect(20, 80, 80, 20));
        buttonConnexion = new QPushButton(MenuConnexion);
        buttonConnexion->setObjectName(QStringLiteral("buttonConnexion"));
        buttonConnexion->setGeometry(QRect(70, 120, 75, 23));
        buttonAnnuler = new QPushButton(MenuConnexion);
        buttonAnnuler->setObjectName(QStringLiteral("buttonAnnuler"));
        buttonAnnuler->setGeometry(QRect(150, 120, 75, 23));
        lineEditPort = new QLineEdit(MenuConnexion);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));
        lineEditPort->setGeometry(QRect(110, 80, 113, 20));
        lineEditNamePlayer = new QLineEdit(MenuConnexion);
        lineEditNamePlayer->setObjectName(QStringLiteral("lineEditNamePlayer"));
        lineEditNamePlayer->setGeometry(QRect(110, 20, 113, 20));
        lineEditIPAddress = new QLineEdit(MenuConnexion);
        lineEditIPAddress->setObjectName(QStringLiteral("lineEditIPAddress"));
        lineEditIPAddress->setGeometry(QRect(110, 50, 113, 20));
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
        labelPort->setText(QApplication::translate("MenuConnexion", "Port :", 0));
        buttonConnexion->setText(QApplication::translate("MenuConnexion", "Connexion", 0));
        buttonAnnuler->setText(QApplication::translate("MenuConnexion", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class MenuConnexion: public Ui_MenuConnexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUCONNEXION_H
