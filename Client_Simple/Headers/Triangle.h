#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Headers/Figure.h"
#include <QtXml>

class Triangle : public Figure
{
private:
	Point p2;
	Point p3;
public:
    Triangle(const Point p1, const Point p2, const Point p3, const Couleur::Couleurs c);
    Triangle(const Triangle &);
    ~Triangle();

    Point getP2()const;
    void setP2(const Point p);

	Point getP3()const;
    void setP3(const Point p);

	void translation(const Point p);
    void rotation();
    void homothetie();

    Triangle* copy() const;
    QDomElement toXml(QDomDocument *) const;
	void afficher(ostream& flux) const;
	friend ostream& operator <<(ostream& flux, const Triangle& t);
};
#endif
