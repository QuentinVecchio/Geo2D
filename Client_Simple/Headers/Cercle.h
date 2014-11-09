#ifndef CERCLE_H
#define CERCLE_H

#include "Headers/Figure.h"
class Cercle :
	public Figure
{
private:
	float rayon;
public:
	Cercle(const Point p, const float r, const Couleur c);
	/*Getters & Setters*/
	float getRayon()const;
	void setRayon(const float r);

	/*Fonctions*/
	void translation(const Point p);
	//void rotation();
	//void homothetie();
	void afficher(ostream& flux) const;
	friend ostream& operator <<(ostream& flux, const Cercle& c);

	~Cercle(){};
};
#endif

