#-------------------------------------------------
#
# Project created by QtCreator 2014-10-27T16:16:19
#
#-------------------------------------------------

QT       += core gui
QT += widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClientGeo2D
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    formulaire.cpp \
    Point/pointcontroller.cpp \
    Point/pointview.cpp \
    Point/point.cpp \
    Abstrait/objetcontroller.cpp

HEADERS  += mainwindow.h \
    formulaire.h \
    Point/pointcontroller.h \
    Point/pointview.h \
    Point/point.h \
    Abstrait/objetcontroller.h

FORMS    += mainwindow.ui