#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <QtXml>
#include <math.h>
using namespace std;

class Point
{
private:
    float x;
    float y;
public:
    *Point();
    *Point(const float x, const float y);
    *Point(const Point& );
    ~Point(){}

    float getX()const;
    float getY()const;

    void setX(const float vx);
    void setY(const float vy);

    void rotation(const Point *origine, float angle);
    void translation(const Point *p);
    void homothetie(const Point *centre, float rapport);

    Point* copy() const;
    QDomElement toXml(QDomDocument *) const;
    void afficher(ostream& flux) const;
    friend ostream& operator <<(ostream& flux, const Point& p);
    friend bool operator == (const Point *p1, const Point p2);
};

#endif // POINT_H
