#-------------------------------------------------
#
# Project created by QtCreator 2015-10-26T08:34:33
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPPoker-Client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clientsock.cpp

HEADERS  += mainwindow.h \
    clientsock.h

FORMS    += mainwindow.ui
