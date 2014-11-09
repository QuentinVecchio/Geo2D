#include "Headers/Figure.h"

Figure::Figure(const Point p1, const Couleur c){
	this->p1 = p1;
	this->c = c;
}

void Figure::translation(Point p){
	p1.setX(p1.getX() + p.getX());
	p1.setY(p1.getY() + p.getY());
}

void Figure::homothetie(){
	// A faire
}

void Figure::rotation(){

}

Point Figure::getP1() const{
	return this->p1;
}
void Figure::setP1(const Point p1){
	this->p1 = p1;
}

Couleur Figure::getC()const{
	return this->c;
}
void Figure::setC(const Couleur c){
	this->c = c;
}

void Figure::afficher(ostream& flux) const{}

ostream& operator <<(ostream& flux, const Figure& f)
{
	f.afficher(flux);
	return flux;
}
