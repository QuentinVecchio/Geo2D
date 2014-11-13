#include "Headers/Point.h"

using namespace std;

Point::Point()
{
    this->x = this->y = 0;
}

Point::Point(const float x, const float y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point& p)
{
    this->x = p.getX();
    this->y = p.getY();
}

float Point::getX()const
{
	return this->x;
}

float Point::getY()const
{
	return this->y;
}

void Point::setX(const float x)
{
	this->x = x;
}

void Point::setY(const float y)
{
	this->y = y;
}

void Point::translation(const Point t)
{
	this->x += t.getX();
	this->y += t.getY();
}

Point* Point::copy() const
{
    return new Point(*this);
}

QDomElement Point::toXml(QDomDocument * dom) const
{
    //Création de la balise point
    QDomElement nom = dom->createElement("point");
    //Création de la balise X
    QDomElement px = dom->createElement("X");
    QString a;
    a.setNum(this->getX());
    QDomText x = dom->createTextNode(a);
    px.appendChild(x);
    nom.appendChild(px);
    //Création de la balise Y
    QDomElement py = dom->createElement("Y");
    a.setNum(this->getY());
    QDomText y = dom->createTextNode(a);
    py.appendChild(y);
    nom.appendChild(py);
    return nom;
}

void Point::afficher(ostream& flux) const
{
	flux << "Point[ x = " << this->x << ", y = " << this->y << "]" << endl;
}

ostream& operator <<(ostream& flux, const Point& p)
{
	p.afficher(flux);
	return flux;
}
