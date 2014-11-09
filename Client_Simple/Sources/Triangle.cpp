#include "Headers/Triangle.h"


Triangle::Triangle(const Point p1, const Point p2, const Point p3, const Couleur c) :Figure(p1,c)
{
	this->p2 = p2;
	this->p3 = p3;
}

void Triangle::setP2(const Point p){
    this->p2 = p;
}
void Triangle::setP3(const Point p){
    this->p3 = p;
}
Point Triangle::getP2()const{
	return this->p2;
}
Point Triangle::getP3()const{
	return this->p3;
}

void Triangle::translation(const Point p){
	Figure::translation(p);
	this->p2.setX(p2.getX() + p.getX());
	this->p2.setY(p2.getY() + p.getY());
	this->p3.setX(p3.getX() + p.getX());
	this->p3.setY(p3.getY() + p.getY());
}
//void rotation();
//void homothetie();
void Triangle::afficher(ostream& flux) const{
	flux << "Triangle[ Point[ x = " << this->getP1().getX() << ", y = " << this->getP1().getY() << "], Point[ x = " << this->getP2().getX() << ", y = " << this->getP2().getY() << "], Point[ x = " << this->getP3().getX() << ", y = " << this->getP3().getY() << "]]" << endl;
}
ostream& operator <<(ostream& flux, const Triangle& t){
	t.afficher(flux);
	return flux;
}
