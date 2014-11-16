#ifndef GROUPE_H
#define GROUPE_H

#include <QtXml>
#include <vector>
#include "../Headers/Figure.h"

class Groupe
{
private:
    Couleur::Couleurs c;
    vector<Figure*> v;
public:
    Groupe(const Couleur::Couleurs c);
    Groupe(const vector<Figure*> groupe, const Couleur::Couleurs c);
    Groupe(const Groupe&);
    ~Groupe();

    void add(Figure *);

    vector<Figure*> getV() const;
    Figure* getFigure(const int i)const;
	int nbElements()const;
    float getAire()const;

    void translation(const Point *p);
    void rotation(const Point *origine, float angle);
    void homothetie(const Point *centre, float rapport);

    Groupe* copy() const;
    QString toXml() const;
	friend ostream& operator <<(ostream& flux, const Groupe& g);
};
#endif

