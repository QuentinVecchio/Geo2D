#include "network.h"
#include <string>
#include <QApplication>
#include <iostream>
#include "Headers/Carre.h"
#include "Headers/Cercle.h"
#include "Headers/Couleur.h"
#include "Headers/Ellipse.h"
#include "Headers/Figure.h"
#include "Headers/Groupe.h"
#include "Headers/Point.h"
#include "Headers/Polygone.h"
#include "Headers/Rectangle.h"
#include "Headers/Segment.h"
#include "Headers/Triangle.h"
#include "Headers/ExceptionGeo2D.h"
#include <iomanip>
using namespace std;

int main(int argc, char * argv[])
{
    /**
      Angles utiles
      90° ==> 1.5707963267949
      180° ==> 3.1415926535898
      270° ==> 4.7123889803847
      360° ==> 6.2831853071796
      */


    QApplication a(argc, argv);
    //Début de programme
        cout << "Bienvenue dans le client simple Geo2D" << endl;
        cout << "Programme développé par Koby Dylan et Vecchio Quentin, élèves de L3" << endl;

    //initialisation de la partie réseau du client
        Network *network = new Network("127.0.0.1","2107");
    //Création des figures
        Groupe *groupe = new Groupe(Couleur::RED);
        Cercle *c1 = new Cercle(new Point(100,600),100,Couleur::CYAN);
        string c = Couleur::getCouleur(c1->getC()).toStdString();
        Cercle *c2 = new Cercle(new Point(300,500),100,Couleur::BLACK);
        Rectangle *r = new Rectangle(new Point(300,200),new Point(500,200),new Point(300,700),new Point(500,700),Couleur::BLACK);
        Segment *s = new Segment(new Point(100,100),new Point(400,140),Couleur::BLACK);
    //Ajout dans un objets groupe
        groupe->add(c1);
        groupe->add(c2);
        groupe->add(r);
        groupe->add(s);

    //Sauvegarde de groupe
        //groupe->save("test.xml");
        //groupe->open("test.xml");

    //Mise en place du xml pour envoie vers serveur
        QString xml1 = groupe->toStringXml();

    //Envoie des données aux serveurs
       network->send(xml1);

   //Fin de programme
       network->close();
       return a.exec();
}
