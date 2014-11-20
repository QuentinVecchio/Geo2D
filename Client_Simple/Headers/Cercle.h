#ifndef CERCLE_H
#define CERCLE_H

#include <QtXml>
#include "QString"
#include "../Headers/Figure.h"

class Cercle : public Figure
{
private:
	float rayon;
public:
    Cercle(const Point *p, const float r, const Couleur::Couleurs c);
    Cercle(const Cercle&);
    ~Cercle();

	float getRayon()const;
	void setRayon(const float r);

    float getAire()const;

    void rotation(const Point *origine, float angle);
    void translation(const Point *p);
    void homothetie(const Point *centre,  float rapport);

    QDomElement toXml(QDomDocument *) const;
    Cercle* copy() const;
	void afficher(ostream& flux) const;
	friend ostream& operator <<(ostream& flux, const Cercle& c);
};
#endif

