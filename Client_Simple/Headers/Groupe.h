#ifndef GROUPE_H
#define GROUPE_H

#include <vector>
#include "Headers/Figure.h"
class Groupe :
	public Figure
{
public:
	vector<Figure*> v;
	Groupe(const Point p1, const Couleur c, const vector<Figure*> polygone);

	/*Getters & Setters*/
	Figure getFigure(const int i)const;
	int nbElements()const;

	/*Fonctions*/
	void translation(const Point p);
	//void rotation();
	//void homothetie();
	friend ostream& operator <<(ostream& flux, const Groupe& g);

	~Groupe(){};
};
#endif

