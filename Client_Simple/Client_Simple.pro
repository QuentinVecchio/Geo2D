#-------------------------------------------------
#
# Project created by QtCreator 2014-11-06T17:11:00
#
#-------------------------------------------------

QT       += core gui
QT += widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client_Simple
TEMPLATE = app


SOURCES += main.cpp\
    network.cpp \
    Sources/Figure.cpp \
    Sources/Polygone.cpp \
    Sources/Groupe.cpp \
    Sources/Triangle.cpp \
    Sources/Segment.cpp \
    Sources/Cercle.cpp \
    Sources/Point.cpp \
    Sources/Couleur.cpp

HEADERS  += \
    network.h \
    Headers/Figure.h \
    Headers/Groupe.h \
    Headers/Polygone.h \
    Headers/Triangle.h \
    Headers/Cercle.h \
    Headers/Segment.h \
    Headers/Point.h \
    Headers/Couleur.h
