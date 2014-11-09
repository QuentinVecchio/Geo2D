#include "Headers/Segment.h"


Segment::Segment(const Point p1, const Point p2, const Couleur c):Figure(p1,c){
	this->p2 = p2;
}

/*Getters & Setters*/

Point Segment::getP2()const{
	return this->p2;
}

void Segment::setP2(const Point p){
	this->p2 = p;
}

/*Fonctions*/
void Segment::translation(const Point p){
	Figure::translation(p);
	this->p2.setX(p2.getX() + p.getX());
	this->p2.setY(p2.getY() + p.getY());
}
//void rotation();
//void homothetie();
void Segment::afficher(ostream& flux) const{
	flux << "Segment[ Point[x = " << this->getP1().getX() << ", y = " << this->getP2().getY() << "] , Point[x = " << this->getP1().getX() << ", y = " << this->getP2().getY() << "]]" << endl;

}

ostream& operator <<(ostream& flux, const Segment& s){
	s.afficher(flux);
	return flux;
}

