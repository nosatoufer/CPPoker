/********************************************************************************
** Form generated from reading UI file 'menucreateroom.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUCREATEROOM_H
#define UI_MENUCREATEROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MenuCreateRoom
{
public:
    QLineEdit *nameRoom;
    QPushButton *buttonCreate;
    QPushButton *buttonCancel;

    void setupUi(QDialog *MenuCreateRoom)
    {
        if (MenuCreateRoom->objectName().isEmpty())
            MenuCreateRoom->setObjectName(QStringLiteral("MenuCreateRoom"));
        MenuCreateRoom->resize(320, 71);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/connexion.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuCreateRoom->setWindowIcon(icon);
        nameRoom = new QLineEdit(MenuCreateRoom);
        nameRoom->setObjectName(QStringLiteral("nameRoom"));
        nameRoom->setGeometry(QRect(10, 10, 301, 20));
        buttonCreate = new QPushButton(MenuCreateRoom);
        buttonCreate->setObjectName(QStringLiteral("buttonCreate"));
        buttonCreate->setGeometry(QRect(10, 40, 141, 23));
        buttonCancel = new QPushButton(MenuCreateRoom);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setGeometry(QRect(170, 40, 141, 23));

        retranslateUi(MenuCreateRoom);

        QMetaObject::connectSlotsByName(MenuCreateRoom);
    } // setupUi

    void retranslateUi(QDialog *MenuCreateRoom)
    {
        MenuCreateRoom->setWindowTitle(QApplication::translate("MenuCreateRoom", "Cr\303\251er une table", 0));
        buttonCreate->setText(QApplication::translate("MenuCreateRoom", "Cr\303\251er", 0));
        buttonCancel->setText(QApplication::translate("MenuCreateRoom", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class MenuCreateRoom: public Ui_MenuCreateRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUCREATEROOM_H
