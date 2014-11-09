#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;
class Point 
{
private:
	float x;
	float y;

public:
	Point(){};
	Point(const float x, const float y);

	/*Getters & Setters*/
	float getX()const;
	float getY()const;

	void setX(const float x);
	void setY(const float y);

	/*Fonctions*/
	void translation(const Point t);

	void afficher(ostream& flux) const;
	friend ostream& operator <<(ostream& flux, const Point& p);

};
#endif

