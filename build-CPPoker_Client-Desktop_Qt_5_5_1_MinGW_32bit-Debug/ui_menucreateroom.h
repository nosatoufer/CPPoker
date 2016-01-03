/********************************************************************************
** Form generated from reading UI file 'menucreateroom.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_MenuCreateRoom
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *minPlayerSpinBox;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QPushButton *buttonCancel;
    QPushButton *buttonCreate;
    QLabel *label_2;
    QSpinBox *maxPlayerSpinBox;
    QLabel *label_5;
    QSpinBox *smallBlindSpinBox;
    QSpinBox *bigBlindSpinBox;

    void setupUi(QDialog *MenuCreateRoom)
    {
        if (MenuCreateRoom->objectName().isEmpty())
            MenuCreateRoom->setObjectName(QStringLiteral("MenuCreateRoom"));
        MenuCreateRoom->resize(381, 218);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/connexion.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuCreateRoom->setWindowIcon(icon);
        gridLayout = new QGridLayout(MenuCreateRoom);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(MenuCreateRoom);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(MenuCreateRoom);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        minPlayerSpinBox = new QSpinBox(MenuCreateRoom);
        minPlayerSpinBox->setObjectName(QStringLiteral("minPlayerSpinBox"));
        minPlayerSpinBox->setMinimum(2);
        minPlayerSpinBox->setMaximum(10);

        gridLayout->addWidget(minPlayerSpinBox, 2, 1, 1, 1);

        label = new QLabel(MenuCreateRoom);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        nameLineEdit = new QLineEdit(MenuCreateRoom);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 1, 1, 1, 1);

        buttonCancel = new QPushButton(MenuCreateRoom);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setAutoDefault(false);

        gridLayout->addWidget(buttonCancel, 6, 1, 1, 1);

        buttonCreate = new QPushButton(MenuCreateRoom);
        buttonCreate->setObjectName(QStringLiteral("buttonCreate"));
        buttonCreate->setAutoDefault(false);

        gridLayout->addWidget(buttonCreate, 6, 0, 1, 1);

        label_2 = new QLabel(MenuCreateRoom);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        maxPlayerSpinBox = new QSpinBox(MenuCreateRoom);
        maxPlayerSpinBox->setObjectName(QStringLiteral("maxPlayerSpinBox"));
        maxPlayerSpinBox->setMinimum(2);
        maxPlayerSpinBox->setMaximum(10);
        maxPlayerSpinBox->setValue(10);

        gridLayout->addWidget(maxPlayerSpinBox, 3, 1, 1, 1);

        label_5 = new QLabel(MenuCreateRoom);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        smallBlindSpinBox = new QSpinBox(MenuCreateRoom);
        smallBlindSpinBox->setObjectName(QStringLiteral("smallBlindSpinBox"));
        smallBlindSpinBox->setMinimum(1);
        smallBlindSpinBox->setMaximum(1000);

        gridLayout->addWidget(smallBlindSpinBox, 4, 1, 1, 1);

        bigBlindSpinBox = new QSpinBox(MenuCreateRoom);
        bigBlindSpinBox->setObjectName(QStringLiteral("bigBlindSpinBox"));
        bigBlindSpinBox->setMinimum(2);
        bigBlindSpinBox->setMaximum(2000);

        gridLayout->addWidget(bigBlindSpinBox, 5, 1, 1, 1);


        retranslateUi(MenuCreateRoom);

        buttonCreate->setDefault(true);


        QMetaObject::connectSlotsByName(MenuCreateRoom);
    } // setupUi

    void retranslateUi(QDialog *MenuCreateRoom)
    {
        MenuCreateRoom->setWindowTitle(QApplication::translate("MenuCreateRoom", "Cr\303\251er une table", 0));
        label_3->setText(QApplication::translate("MenuCreateRoom", "Nombre de joueurs maximum", 0));
        label_4->setText(QApplication::translate("MenuCreateRoom", "Valeur de la small blind", 0));
        label->setText(QApplication::translate("MenuCreateRoom", "Nom", 0));
        buttonCancel->setText(QApplication::translate("MenuCreateRoom", "Annuler", 0));
        buttonCreate->setText(QApplication::translate("MenuCreateRoom", "Cr\303\251er", 0));
        label_2->setText(QApplication::translate("MenuCreateRoom", "Nombre de joueurs minimum", 0));
        label_5->setText(QApplication::translate("MenuCreateRoom", "Valeur de la big blind", 0));
    } // retranslateUi

};

namespace Ui {
    class MenuCreateRoom: public Ui_MenuCreateRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUCREATEROOM_H
