#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Headers/Figure.h"
class Triangle :
	public Figure
{
private:
	Point p2;
	Point p3;
public:
	Triangle(const Point p1, const Point p2, const Point p3, const Couleur c);

	/*Getters & Setters*/
    void setP2(const Point p);
    void setP3(const Point p);
	Point getP2()const;
	Point getP3()const;

	/*Fonctions*/
	void translation(const Point p);
	//void rotation();
	//void homothetie();
	void afficher(ostream& flux) const;
	friend ostream& operator <<(ostream& flux, const Triangle& t);
	~Triangle(){};
};
#endif
