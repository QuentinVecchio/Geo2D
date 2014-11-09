#ifndef POLYGONE_H
#define POLYGONE_H

#include <vector>
#include "Headers/Segment.h"
class Polygone :
	public Segment
{

public:
	vector<Segment*> v;
	Polygone(const Point p1, const Point p2, const Couleur c, const vector<Segment*> polygone);

	/*Getters & Setters*/
	Segment getSegment(const int i)const;
	int nbElements()const;

	/*Fonctions*/
	void translation(const Point p);
	//void rotation();
	//void homothetie();
	friend ostream& operator <<(ostream& flux, const Polygone& p);

	~Polygone(){};
};

#endif
