#ifndef SEGMENT_H
#define SEGMENT_H

#include "Headers/Figure.h"
class Segment :
	public Figure
{
private:
	Point p2;
public:
	Segment(const Point p1, const Point p2, const Couleur c);

	/*Getters & Setters*/
	Point getP2()const;
	void setP2(const Point p);

	/*Fonctions*/
	void translation(const Point p);
	//void rotation();
	//void homothetie();
	void afficher(ostream& flux) const;
	friend ostream& operator <<(ostream& flux, const Segment& s);

	~Segment(){};
};
#endif

