#include "network.h"
#include <string>
#include <iostream>
#include "Headers/Cercle.h"
#include "Headers/Couleur.h"
#include "Headers/Figure.h"
#include "Headers/Groupe.h"
#include "Headers/Point.h"
#include "Headers/Polygone.h"
#include "Headers/Segment.h"
#include "Headers/Triangle.h"

using namespace std;

int main()
{

    /**
     * Main pour Dylan
     *
    */
    float pi = 4.0 * atan(1.0);
    Point *p1 = new Point(1, 1);
    Point *p2 = new Point(3,3);
    Segment *s1 = new Segment(*p1, *p2, Couleur::BLACK);
    cout << *s1;
    s1->rotation(*p2, 1.5707963267949);
    cout << *s1;

    /*
    //Début de programme
        cout << "Bienvenue dans le client simple Geo2D" << endl;
        cout << "Programme développé par Koby Dylan et Vecchio Quentin, élèves de L3" << endl;

    //initialisation de la partie réseau du client
        Network *network = new Network("127.0.0.1","2107");

    //Création des figures
        Groupe *groupe = new Groupe();
        Cercle *c = new Cercle(Point(2,3),2.5,Couleur::BLACK);
        Segment *s = new Segment(Point(1,1),Point(2,2),Couleur::BLACK);
        Triangle *t = new Triangle(Point(1,1),Point(2,2),Point(3,3),Couleur::BLACK);
        //Création d'un polygone
        Segment *s1 = new Segment(Point(1,1),Point(2,2),Couleur::BLACK);
        Segment *s2 = new Segment(Point(1,1),Point(2,2),Couleur::BLACK);
        vector<Segment *> vec;
        vec.push_back(s1);
        vec.push_back(s2);
        Polygone *p = new Polygone(Point(1,1),Couleur::BLACK,vec);

    //Ajout dans un objets groupe
        groupe->add(c);
        groupe->add(s);
        groupe->add(t);
        groupe->add(p);

    //Mise en place du xml pour envoie vers serveur
        QString xml = groupe->toXml();
        string e = xml.toStdString();
        cout << e << endl;

    //Envoie des données aux serveurs
       network->send(xml);

    //Fin de programme
        exit(0);
    */
}