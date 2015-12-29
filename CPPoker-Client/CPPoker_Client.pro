#-------------------------------------------------
#
# Project created by QtCreator 2015-11-13T13:43:32
#
#-------------------------------------------------

QT += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = poker_client
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    main.cpp \
    view/menuconnexion.cpp \
    view/pokerclientgui.cpp \
    view/pokerwidget.cpp \
    view/playerwidget.cpp \
    network/clientsock.cpp \
    network/request.cpp \
    network/utils.cpp

FORMS += \
    view/menuconnexion.ui \
    view/pokerclientgui.ui

HEADERS += \
    view/menuconnexion.h \
    view/pokerclientgui.h \
    view/pokerwidget.h \
    view/playerwidget.h \
    network/clientsock.h \
    network/commands.h \
    network/request.h \
    network/utils.h

RESOURCES += \
    images.qrc
