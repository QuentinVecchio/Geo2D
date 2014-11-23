#-------------------------------------------------
#
# Project created by QtCreator 2014-11-06T17:11:00
#
#-------------------------------------------------

QT       += core gui widgets
QT += widgets network
QT += xml
QT += qml

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
    Sources/Couleur.cpp \
    Sources/ExceptionGeo2D.cpp \
    Constructeur_Sources/Constructeur.cpp \
    Constructeur_Sources/ConstructeurCOR.cpp \
    Constructeur_Sources/ConstructeurCercle.cpp \
    Constructeur_Sources/ConstructeurPolygone.cpp \
    Constructeur_Sources/ConstructeurSegment.cpp \
    Constructeur_Sources/ConstructeurTriangle.cpp \
    Constructeur_Sources/ConstructeurGroupe.cpp \
    Sources/Carre.cpp \
    Sources/Rectangle.cpp \
    Sources/Ellipse.cpp

HEADERS  += \
    network.h \
    Headers/Figure.h \
    Headers/Groupe.h \
    Headers/Polygone.h \
    Headers/Triangle.h \
    Headers/Cercle.h \
    Headers/Segment.h \
    Headers/Point.h \
    Headers/Couleur.h \
    Headers/ExceptionGeo2D.h \
    Constructeur_Headers/constructeur.h \
    Constructeur_Headers/ConstructeurCOR.h \
    Constructeur_Headers/ConstructeurSegment.h \
    Constructeur_Headers/ConstructeurTriangle.h \
    Constructeur_Headers/ConstructeurCercle.h \
    Constructeur_Headers/ConstructeurPolygone.h \
    Constructeur_Headers/ConstructeurGroupe.h \
    Headers/Carre.h \
    Headers/Rectangle.h \
    Headers/Ellipse.h
