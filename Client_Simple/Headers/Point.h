#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <QtXml>

using namespace std;

class Point 
{
private:
	float x;
	float y;

public:
    Point();
	Point(const float x, const float y);
    Point(const Point& );

	float getX()const;
	float getY()const;

	void setX(const float x);
	void setY(const float y);

	void translation(const Point t);
    void homothetie();

    Point* copy() const;
    QDomElement toXml(QDomDocument *) const;
	void afficher(ostream& flux) const;
	friend ostream& operator <<(ostream& flux, const Point& p);
    friend bool operator == (const Point p1, const Point p2);
};
#endif

