#ifndef GROUPE_H
#define GROUPE_H

#include <QtXml>
#include <vector>
#include "../Headers/Figure.h"

class Groupe
{
private:
    vector<Figure*> v;
public:
    Groupe();
    Groupe(const vector<Figure*> polygone);
    Groupe(const Groupe&);
    ~Groupe();

    void add(Figure *);

    vector<Figure*> getV() const;
    Figure* getFigure(const int i)const;
	int nbElements()const;

	void translation(const Point p);
    void rotation(Point origine, float angle);
    void homothetie();

    Groupe* copy() const;
    QString toXml() const;
	friend ostream& operator <<(ostream& flux, const Groupe& g);
};
#endif

