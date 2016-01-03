/********************************************************************************
** Form generated from reading UI file 'menuchooseroom.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUCHOOSEROOM_H
#define UI_MENUCHOOSEROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MenuChooseRoom
{
public:
    QListWidget *tableRooms;
    QPushButton *buttonConnexion;
    QPushButton *buttonCancel;
    QPushButton *buttonCreate;

    void setupUi(QDialog *MenuChooseRoom)
    {
        if (MenuChooseRoom->objectName().isEmpty())
            MenuChooseRoom->setObjectName(QStringLiteral("MenuChooseRoom"));
        MenuChooseRoom->resize(320, 240);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/connexion.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuChooseRoom->setWindowIcon(icon);
        MenuChooseRoom->setSizeGripEnabled(false);
        MenuChooseRoom->setModal(false);
        tableRooms = new QListWidget(MenuChooseRoom);
        tableRooms->setObjectName(QStringLiteral("tableRooms"));
        tableRooms->setGeometry(QRect(10, 10, 301, 191));
        buttonConnexion = new QPushButton(MenuChooseRoom);
        buttonConnexion->setObjectName(QStringLiteral("buttonConnexion"));
        buttonConnexion->setGeometry(QRect(10, 210, 101, 23));
        buttonCancel = new QPushButton(MenuChooseRoom);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setGeometry(QRect(220, 210, 91, 23));
        buttonCreate = new QPushButton(MenuChooseRoom);
        buttonCreate->setObjectName(QStringLiteral("buttonCreate"));
        buttonCreate->setGeometry(QRect(120, 210, 91, 23));

        retranslateUi(MenuChooseRoom);

        QMetaObject::connectSlotsByName(MenuChooseRoom);
    } // setupUi

    void retranslateUi(QDialog *MenuChooseRoom)
    {
        MenuChooseRoom->setWindowTitle(QApplication::translate("MenuChooseRoom", "Choisir une table", 0));
        buttonConnexion->setText(QApplication::translate("MenuChooseRoom", "Connexion", 0));
        buttonCancel->setText(QApplication::translate("MenuChooseRoom", "Annuler", 0));
        buttonCreate->setText(QApplication::translate("MenuChooseRoom", "Cr\303\251er table", 0));
    } // retranslateUi

};

namespace Ui {
    class MenuChooseRoom: public Ui_MenuChooseRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUCHOOSEROOM_H
