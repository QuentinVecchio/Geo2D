#include "../Headers/Point.h"

using namespace std;
*Point::Point(){
    this->x = 0;
    this->y = 0;
}

*Point::Point(const float x, const float y)
{
	this->x = x;
	this->y = y;
}

*Point::Point(const Point &p)
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

void Point::rotation(const Point *origine, float angle)
{
    // si on tourne autour de l'origine O(0,0)
    if(origine == Point(0.0, 0.0)){
        double X = this->x - origine->getX();
        double Y = this->y - origine->getY();
        double newx = origine->getX() + X * cos(angle) - Y * sin(angle);
        double newy = origine->getY() + X * sin(angle) + Y * cos(angle);
        this->x = newx;
        this->y = newy;
    }
    else{
        double newx = (this->x - origine->getX()) * cos(angle) - (this->y - origine->getY()) * sin(angle) + origine->getX();
        double newy = (this->y - origine->getY()) * cos(angle) + (this->x - origine->getX()) * sin(angle) + origine->getY();
        this->x = newx;
        this->y = newy;
    }
}

void Point::translation(const Point *p)
{
    this->x += p->getX();
    this->y += p->getY();
}

void Point::homothetie(const Point *centre, float rapport){
    if(rapport == 1){
        cout << "Le point reste invariant avec un rapport de 1" << endl;
    }
    else{
        this->setX(centre->getX() + rapport);
        this->setY(centre->getY() + rapport);
    }
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

bool operator == (const Point *p1, const Point p2){
    return (p1->getX() == p2.getX()) && (p1->getY() == p2.getY());
}
