#include "Headers/Point.h"

using namespace std;

Point::Point(const float x, const float y)
{
	this->x = x;
	this->y = y;
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

void Point::translation(const Point t){
	this->x += t.getX();
	this->y += t.getY();
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



