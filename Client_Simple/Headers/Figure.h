#ifndef FIGURE_H
#define FIGURE_H

#include "Headers/Point.h"
#include "Headers/Couleur.h"
#include <iostream>
using namespace std;

class Figure{
private:
	Couleur c;
	Point p1;
public:
	Figure(){};
	Figure(const Point p1, const Couleur c);
	void translation(Point p);
	void homothetie();
	void rotation();

	Point getP1() const;
	void setP1(const Point p1);

	Couleur getC()const;
	void setC(const Couleur c);

	void afficher(ostream& flux) const;
	friend ostream& operator <<(ostream& flux, const Figure& f);
};
#endif
