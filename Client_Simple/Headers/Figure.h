#ifndef FIGURE_H
#define FIGURE_H

#include "../Headers/Point.h"
#include "../Headers/Couleur.h"
#include <iostream>
#include <QtXml>

using namespace std;

class Figure{

private:
    Couleur::Couleurs c;
    Point *p1;
protected:

    Figure(){}
    Figure(const Figure&);
    Figure(const Point *p1, const Couleur::Couleurs c);

public:
    ~Figure(){}

    virtual void translation(const Point *p) = 0;
    virtual void homothetie(const Point *p , float rapport) = 0;
    virtual void rotation(const Point *p, float rapport) = 0;

    Point *getP1() const;
    Couleur::Couleurs getC()const;

    void setP1(const Point *p);
    void setC(const Couleur::Couleurs c);

    float getAire()const{ return NULL;}

    virtual QDomElement toXml(QDomDocument *) const = 0;
    virtual void afficher(ostream& flux) const;
    virtual Figure* copy() const = 0;
	friend ostream& operator <<(ostream& flux, const Figure& f);
};
#endif
