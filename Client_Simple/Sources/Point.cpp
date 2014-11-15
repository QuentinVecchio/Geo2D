#include "../Headers/Point.h"

using namespace std;
Point::Point(){
    this->x = 0;
    this->y = 0;
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

void Point::setX(const float vx)
{
    this->x = vx;
}

void Point::setY(const float vy)
{
    this->y = vy;
}

void Point::rotation(const Point origine, float angle)
{
    float PI = 4.0 * atan(1.0);
    double newx = (x - origine.getX()) * cos(angle * PI / 180) - (y - origine.getY()) * sin(angle * PI / 180) + 1;
    double newy = (x - origine.getX()) * sin(angle * PI / 180) + (y - origine.getY()) * cos(angle * PI / 180) + 1;
    this->x = newx;
    this->y = newy;

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

bool operator == (const Point p1, const Point p2){
    return (p1.getX() == p2.getX()) && (p2.getY() == p2.getY());
}
