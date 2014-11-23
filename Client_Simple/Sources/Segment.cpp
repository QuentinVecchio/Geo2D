#include "../Headers/Segment.h"
#include <math.h>

Segment::Segment(const Point *p1, const Point *p2, const Couleur::Couleurs c):Figure(p1->copy(),c)
{
    this->p2 = p2->copy();
}

Segment::Segment(const Segment &s) :Figure(s.getP1()->copy(),s.getC())
{
    this->p2 = s.getP2();
}

Point *Segment::getP2() const
{
    return this->p2;
}

void Segment::setP2(const Point *p)
{
    this->p2 = p->copy();
}

float Segment::getLongueur()const{
    int deltaX = this->getP2()->getX()- this->getP1()->getX();
    int deltaY = this->getP2()->getY()- this->getP1()->getY();
    return sqrt(deltaX*deltaX + deltaY*deltaY);
}

void Segment::translation(const Point *p)
{
    this->setP1(Point(this->getP1()->getX() + p->getX(), this->getP1()->getY() + p->getY()).copy());
    this->p2->setX(p2->getX() + p->getX());
    this->p2->setY(p2->getY() + p->getY());
}

Segment* Segment::copy() const
{
    return new Segment(*this);
}

void Segment::rotation(const Point *origine, double angle)
{
    // Construction du nouveau point selon le point d'origine donné
    if (origine == *this->getP1()){
        float X2 = this->p2->getX() - origine->getX();
        float Y2 = this->p2->getY() - origine->getY();
        float newx2 = origine->getX() + X2 * cos(angle) - Y2 * sin(angle);
        float newy2 = origine->getY() + X2 * sin(angle) + Y2 * cos(angle);
        this->p2->setX(newx2);
        this->p2->setY(newy2);
    }
    else if (origine == *this->p2){
        float X = this->getP1()->getX() - origine->getX();
        float Y = this->getP1()->getY() - origine->getY();
        float newx = origine->getX() + X * cos(angle) - Y * sin(angle);
        float newy = origine->getY() + X * sin(angle) + Y * cos(angle);
        this->setP1(Point(newx, newy).copy());
    }
    else if(origine == Point(0.0, 0.0)){
        float X = this->getP1()->getX() - origine->getX();
        float Y = this->getP1()->getY() - origine->getY();
        float newx = origine->getX() + X * cos(angle) - Y * sin(angle);
        float newy = origine->getY() + X * sin(angle) + Y * cos(angle);
        this->setP1(Point(newx, newy).copy());

        float X2 = this->p2->getX() - origine->getX();
        float Y2 = this->p2->getY() - origine->getY();
        float newx2 = origine->getX() + X2 * cos(angle) - Y2 * sin(angle);
        float newy2 = origine->getY() + X2 * sin(angle) + Y2 * cos(angle);
        this->p2->setX(newx2);
        this->p2->setY(newy2);
    }
}

void Segment::homothetie(const Point *centre, float rapport)
{
    if(rapport == 1){
        cout << "Les points restent invariants avec un rapport de 1" << endl;
    }
    else{
        if(centre == *this->getP1()){
            this->p2->setX(this->getP1()->getX() + rapport);
            this->p2->setY(this->getP1()->getY() + rapport);
        }
        else if(centre == *this->p2){
            this->setP1(Point(this->p2->getX() - rapport, this->p2->getY() - rapport).copy());
        }
    }
}

QDomElement Segment::toXml(QDomDocument * dom) const
{
    //Création de la balise segment
    QDomElement nom = dom->createElement("segment");
    //Création de la balise point1
    QDomElement point = this->getP1()->toXml(dom);
    nom.appendChild(point);
    //Création de la balise point2
    QDomElement point1 = this->getP2()->toXml(dom);
    nom.appendChild(point1);
    //Création de la balise couleur
    QDomElement couleur = dom->createElement("couleur");
    QDomText c = dom->createTextNode(Couleur::getCouleur(this->getC()));
    couleur.appendChild(c);
    nom.appendChild(couleur);
    return nom;
}

void Segment::afficher(ostream& flux) const
{
    flux << "Segment[ Point[x = " << this->getP1()->getX() << ", y = " << this->getP1()->getY() << "] , Point[x = " << this->getP2()->getX() << ", y = " << this->getP2()->getY() << "]" << ", couleur = " << Couleur::getCouleur(this->getC()).toStdString() << "]" << endl;
}

ostream& operator <<(ostream& flux, const Segment& s)
{
    s.afficher(flux);
    return flux;
}

Segment::~Segment(){
    delete this->getP1();
    delete this->p2;
}

