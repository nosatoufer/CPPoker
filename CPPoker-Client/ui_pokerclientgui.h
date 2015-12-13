/********************************************************************************
** Form generated from reading UI file 'pokerclientgui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POKERCLIENTGUI_H
#define UI_POKERCLIENTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PokerClientGui
{
public:
    QAction *actionConnexion;
    QAction *actionDeconnexion;
    QAction *actionQuitter;
    QAction *actionApropos;
    QAction *actionRegles;
    QAction *actionCombinaisons;
    QAction *actionNouveauSalon;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuPartie;
    QMenu *menuAide;

    void setupUi(QMainWindow *PokerClientGui)
    {
        if (PokerClientGui->objectName().isEmpty())
            PokerClientGui->setObjectName(QStringLiteral("PokerClientGui"));
        PokerClientGui->resize(300, 100);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/logoPoker.png"), QSize(), QIcon::Normal, QIcon::Off);
        PokerClientGui->setWindowIcon(icon);
        actionConnexion = new QAction(PokerClientGui);
        actionConnexion->setObjectName(QStringLiteral("actionConnexion"));
        actionDeconnexion = new QAction(PokerClientGui);
        actionDeconnexion->setObjectName(QStringLiteral("actionDeconnexion"));
        actionQuitter = new QAction(PokerClientGui);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionApropos = new QAction(PokerClientGui);
        actionApropos->setObjectName(QStringLiteral("actionApropos"));
        actionRegles = new QAction(PokerClientGui);
        actionRegles->setObjectName(QStringLiteral("actionRegles"));
        actionCombinaisons = new QAction(PokerClientGui);
        actionCombinaisons->setObjectName(QStringLiteral("actionCombinaisons"));
        actionNouveauSalon = new QAction(PokerClientGui);
        actionNouveauSalon->setObjectName(QStringLiteral("actionNouveauSalon"));
        centralWidget = new QWidget(PokerClientGui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PokerClientGui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PokerClientGui);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 300, 21));
        menuPartie = new QMenu(menuBar);
        menuPartie->setObjectName(QStringLiteral("menuPartie"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        PokerClientGui->setMenuBar(menuBar);

        menuBar->addAction(menuPartie->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuPartie->addAction(actionConnexion);
        menuPartie->addAction(actionNouveauSalon);
        menuPartie->addSeparator();
        menuPartie->addAction(actionDeconnexion);
        menuPartie->addSeparator();
        menuPartie->addAction(actionQuitter);
        menuPartie->addSeparator();
        menuPartie->addAction(actionApropos);
        menuAide->addAction(actionRegles);
        menuAide->addAction(actionCombinaisons);

        retranslateUi(PokerClientGui);

        QMetaObject::connectSlotsByName(PokerClientGui);
    } // setupUi

    void retranslateUi(QMainWindow *PokerClientGui)
    {
        PokerClientGui->setWindowTitle(QApplication::translate("PokerClientGui", "Poker - Texas Hold'em", 0));
        actionConnexion->setText(QApplication::translate("PokerClientGui", "Connexion", 0));
        actionConnexion->setShortcut(QString());
        actionDeconnexion->setText(QApplication::translate("PokerClientGui", "Se d\303\251connecter", 0));
        actionQuitter->setText(QApplication::translate("PokerClientGui", "Quitter", 0));
        actionApropos->setText(QApplication::translate("PokerClientGui", "A propos", 0));
        actionRegles->setText(QApplication::translate("PokerClientGui", "R\303\250gles", 0));
        actionCombinaisons->setText(QApplication::translate("PokerClientGui", "Combinaisons", 0));
        actionNouveauSalon->setText(QApplication::translate("PokerClientGui", "Nouveau salon", 0));
        menuPartie->setTitle(QApplication::translate("PokerClientGui", "Partie", 0));
        menuAide->setTitle(QApplication::translate("PokerClientGui", "Aide", 0));
    } // retranslateUi

};

namespace Ui {
    class PokerClientGui: public Ui_PokerClientGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POKERCLIENTGUI_H
