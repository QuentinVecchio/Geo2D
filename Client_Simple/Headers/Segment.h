#ifndef SEGMENT_H
#define SEGMENT_H

#include "Headers/Figure.h"
#include <QtXml>

class Segment : public Figure
{
private:
	Point p2;
public:
    Segment(const Point p1, const Point p2, const Couleur::Couleurs c);
    Segment(const Segment&);
    ~Segment();

	Point getP2()const;
	void setP2(const Point p);

	void translation(const Point p);
    void rotation();
    void homothetie();

    virtual Segment* copy() const;
    QDomElement toXml(QDomDocument *) const;
	void afficher(ostream& flux) const;
	friend ostream& operator <<(ostream& flux, const Segment& s);
};
#endif

