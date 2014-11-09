#include "Headers/Cercle.h"


Cercle::Cercle(const Point p, const float r, const Couleur c):Figure(p,c){
	this->rayon = r;
}
/*Getters & Setters*/
float Cercle::getRayon()const{
	return this->rayon;
}
void Cercle::setRayon(const float r){
	this->rayon = r;
}

/*Fonctions*/
void Cercle::translation(const Point p){
	Figure::translation(p);
}
//void rotation();
//void homothetie();
void Cercle::afficher(ostream& flux) const{
	flux << "Cercle[ Point[ x = " << this->getP1().getX() << ", y = " << this->getP1().getY() << "], " << " Rayon = " << this->rayon << "] " << endl;
}
ostream& operator <<(ostream& flux, const Cercle& c){
	c.afficher(flux);
	return flux;
}
