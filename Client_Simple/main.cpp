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

    /*
    Groupe *g = new Groupe(Couleur::GREEN);
    */

    /**
      Test carre
      */
/*
    Point *p1 = new Point(1.0,1.0);
    Point *p2 = new Point(1.0,3.0);
    Point *p3 = new Point(3.0,3.0);
    Point *p4 = new Point(3.0,1.0);
    Carre *ca = new Carre(p1, p2, p3, p4, Couleur::RED);
    cout << *ca;
    //ca->translation(Point(2.0, 2.0).copy());
    //ca->rotation(p3, 3.1415926535898);
    //ca->homothetie(p1, 2);
    cout << *ca;
*/
    /**
      Test rectangle
      */
/*
    Point *p1 = new Point(1.0,1.0);
    Point *p2 = new Point(1.0,3.0);
    Point *p3 = new Point(4.0,3.0);
    Point *p4 = new Point(4.0,1.0);
    Rectangle *r = new Rectangle(p1, p2, p3, p4, Couleur::RED);
    cout << *r;
    //r->translation(Point(2.0, 2.0).copy());
    //r->rotation(p3, 3.1415926535898);
    //r->homothetie(p1, 2);
    cout << r->getAire();
*/

    /**
      Test point
      */
    /*
    Point *p1 = new Point(1.0,1.0);
    Point *p2 = new Point(2.0,2.0);
    Point *p3 = new Point(3.0,1.0);
    cout << *p2;
    p2->rotation(p1, 6.2831853071796);
    cout << *p2;
    */

    /**
      Test segment
      */
/*
    Point *p1 = new Point(1.0,1.0);
    Point *p2 = new Point(2.0,2.0);
    Point *p3 = new Point(10.0, 10.0);
    Segment *s1 = new Segment(p1, p2, Couleur::CYAN);
    cout << *s1;
    s1->rotation(p1, 3.1415926535898);
    cout << *s1;
*/

    /**
      Test cercle
      */
/*
    Point *p1 = new Point(1.0,1.0);
    Point *p2 = new Point(2.0,2.0);
    Cercle *c = new Cercle(p2, 1.0, Couleur::BLACK);
    cout << *c;
    c->rotation(p1, 6.2831853071796);
    cout << *c;
*/

    /**
      Test ellipse
      */
/*
    Point *p1 = new Point(1.0,1.0);
    Point *p2 = new Point(2.0,2.0);
    Ellipse *e = new Ellipse(p2, p1, 1.0, Couleur::CYAN);
    cout << *e;
    e->rotation(p1, 6.2831853071796);
    cout << *e;
*/

    /**
      Test triangle, homothetie à faire
      */
/*
    Point *p1 = new Point(1.0,1.0);
    Point *p2 = new Point(2.0,3.0);
    Point *p3 = new Point(3.0, 1.0);
    Triangle *t = new Triangle(p1, p2, p3, Couleur::CYAN);
    cout << *t;
    t->rotation(p1, 3.1415926535898);
    cout << *t;
*/
    /**
      Test polygone, rotation à revoir via segment, homothetie à revoir
      */
    /*
    Point *p1 = new Point(1.0,1.0);
    Point *p2 = new Point(2.0,2.0);
    Point *p3 = new Point(5.0, 5.0);
    Segment *s1 = new Segment(p1, p2, Couleur::CYAN);
    Segment *s2 = new Segment(p2, p3, Couleur::RED);
    Polygone *p = new Polygone(p3, Couleur::BLUE);
    p->add(s1); p->add(s2);
    cout << *p;
    p->homothetie(p2, 2);
    cout << *p;
    */

    /*
    //Main pour Quentin
    QApplication a(argc, argv);
    //Début de programme
        cout << "Bienvenue dans le client simple Geo2D" << endl;
        cout << "Programme développé par Koby Dylan et Vecchio Quentin, élèves de L3" << endl;

    //initialisation de la partie réseau du client
        Network *network = new Network("127.0.0.1","2107");

    //Création des figures
        Groupe *groupe = new Groupe(Couleur::BLACK);
        Cercle *c = new Cercle(new Point(200,200),200,Couleur::BLACK);
        Segment *s = new Segment(new Point(1,1),new Point(200,200),Couleur::BLACK);
        Triangle *t = new Triangle(new Point(1,1),new Point(150,200),new Point(300,100),Couleur::BLACK);
        //Création d'un polygone
        Segment *s1 = new Segment(new Point(1,1),new Point(250,250),Couleur::BLACK);
        Segment *s2 = new Segment(new Point(250,250),new Point(400,400),Couleur::BLACK);
        vector<Segment *> vec;
        vec.push_back(s1);
        vec.push_back(s2);
        Polygone *p = new Polygone(new Point(1,1),Couleur::BLACK,vec);

    //Ajout dans un objets groupe
        groupe->add(c);
        groupe->add(s);
        groupe->add(t);
        groupe->add(p);

    //Sauvegarde de groupe
        groupe->save("/Users/quentinvecchio/Desktop/test.xml");
        groupe->open("/Users/quentinvecchio/Desktop/test.xml");

    //Mise en place du xml pour envoie vers serveur
        QString xml = groupe->toStringXml();
        string e = xml.toStdString();
        cout << e << endl;

    //Envoie des données aux serveurs
       network->send(xml);

   //Fin de programme
       return a.exec();
       */
}
