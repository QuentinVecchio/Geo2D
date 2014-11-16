#ifndef POLYGONE_H
#define POLYGONE_H

#include <vector>
#include "../Headers/Segment.h"
#include <QtXml>

class Polygone : public Figure
{
private:
    vector<Segment*> v;
public:
    Polygone(const Point*, const Couleur::Couleurs);
    Polygone(const Point *p, const Couleur::Couleurs, const vector<Segment*> polygone);
    Polygone(const Polygone&);
    ~Polygone();

    void add(Segment *s);

    vector<Segment*> getV() const;
    Segment* getSegment(const int i)const;
	int nbElements()const;
    float getAire()const;

    void translation(const Point *p);
    void rotation(const Point *origine, float angle);
    void homothetie(const Point *centre, float rapport);

    Polygone* copy() const;
    QDomElement toXml(QDomDocument *) const;
	friend ostream& operator <<(ostream& flux, const Polygone& p);
};

#endif
