#include "../Headers/Segment.h"

Segment::Segment(const Point p1, const Point p2, const Couleur::Couleurs c):Figure(p1,c)
{
    this->p2 = p2;
}

Segment::Segment(const Segment& s) :Figure(s.getP1(),s.getC())
{
    this->p2 = s.getP2();
}

Segment::~Segment()
{}

Point Segment::getP2() const
{
    return this->p2;
}

void Segment::setP2(const Point p)
{
    this->p2 = p;
}

void Segment::translation(const Point p)
{
    this->getP1().setX(getP1().getX() + p.getX());
    this->getP1().setY(getP1().getY() + p.getY());
    this->p2.setX(p2.getX() + p.getX());
    this->p2.setY(p2.getY() + p.getY());
}

Segment* Segment::copy() const
{
    return new Segment(*this);
}

void Segment::rotation(const Point origine, float angle)
{
    float PI = 4.0 * atan(1.0);
    //Conversion angle en degré car donné en radian
    angle = 180 * ((angle) / PI);

    // Construction du nouveau point selon le point d'origine donné
    if (origine == this->getP1()){
        double newx = (this->p2.getX() - origine.getX()) * cos(angle * PI / 180) - (this->p2.getY() - origine.getY()) * sin(angle * PI / 180) + 1;
        double newy = (this->p2.getX() - origine.getX()) * sin(angle * PI / 180) + (this->p2.getY() - origine.getY()) * cos(angle * PI / 180) + 1;
        this->p2.setX(newx);
        this->p2.setY(newy);
    }
    else if (origine == this->p2){
        double newx = (this->getP1().getX() - origine.getX()) * cos(angle * PI / 180) - (this->getP1().getY() - origine.getY()) * sin(angle * PI / 180) + 1;
        double newy = (this->getP1().getX() - origine.getX()) * sin(angle * PI / 180) + (this->getP1().getY() - origine.getY()) * cos(angle * PI / 180) + 1;
        cout << newx  << "/" << newy << endl;
        this->getP1().setX(350.0);
        this->getP1().setY(350.0);
        cout << this->getP1();
    }
    else{
        /*
        double x = (this->p2.getX() - origine.getX()) * cos(angle * PI / 180) - (this->p2.getY() - origine.getY()) * sin(angle * PI / 180) + 1;
        double y = (this->p2.getX() - origine.getX()) * sin(angle * PI / 180) + (this->p2.getY() - origine.getY()) * cos(angle * PI / 180) + 1;
        this->p2.setX(x);
        this->p2.setY(y);
        */
    }
}

void Segment::homothetie()
{
    cout << "homothetie";
}

QDomElement Segment::toXml(QDomDocument * dom) const
{
    //Création de la balise segment
    QDomElement nom = dom->createElement("segment");
    //Création de la balise point1
    QDomElement point = this->getP1().toXml(dom);
    nom.appendChild(point);
    //Création de la balise point2
    QDomElement point1 = this->getP2().toXml(dom);
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
    flux << "Segment[ Point[x = " << this->getP1().getX() << ", y = " << this->getP1().getY() << "] , Point[x = " << this->getP2().getX() << ", y = " << this->getP2().getY() << "]" << ", couleur = " << Couleur::getCouleur(this->getC()).toStdString() << "]" << endl;

}

ostream& operator <<(ostream& flux, const Segment& s)
{
    s.afficher(flux);
    return flux;
}

