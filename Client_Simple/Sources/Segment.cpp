#include "Headers/Segment.h"

Segment::Segment(const Point p1, const Point p2, const Couleur::Couleurs c):Figure(p1,c)
{
	this->p2 = p2;
}

Segment::Segment(const Segment& s) :Figure(s.getP1(),s.getC())
{
    this->p2 = s.getP2();
}

Segment::~Segment()
{

}

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
	Figure::translation(p);
	this->p2.setX(p2.getX() + p.getX());
	this->p2.setY(p2.getY() + p.getY());
}

Segment* Segment::copy() const
{
    return new Segment(*this);
}

void Segment::rotation()
{

}

void Segment::homothetie()
{

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
	flux << "Segment[ Point[x = " << this->getP1().getX() << ", y = " << this->getP2().getY() << "] , Point[x = " << this->getP1().getX() << ", y = " << this->getP2().getY() << "]]" << endl;

}

ostream& operator <<(ostream& flux, const Segment& s)
{
	s.afficher(flux);
	return flux;
}

