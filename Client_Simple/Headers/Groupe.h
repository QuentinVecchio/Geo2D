#ifndef GROUPE_H
#define GROUPE_H

#include <QtXml>
#include "QFile"
#include "QTextStream"
#include <vector>
#include "../Headers/Figure.h"
#include "../Constructeur_Headers/ConstructeurCOR.h"
#include "../Constructeur_Headers/ConstructeurCercle.h"
#include "../Constructeur_Headers/ConstructeurSegment.h"
#include "../Constructeur_Headers/ConstructeurTriangle.h"
#include "../Constructeur_Headers/ConstructeurPolygone.h"
#include "../Constructeur_Headers/ConstructeurGroupe.h"

class Groupe : public Figure
{
private:
    Couleur::Couleurs c;
    vector<Figure*> v;
    QDomDocument *dom;
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
    void rotation(const Point *origine, double angle);
    void homothetie(const Point *centre, float rapport);

    Groupe* copy() const;
    void afficher(ostream& flux) const;
    QDomElement toXml(QDomDocument *) const;
    QString toStringXml() const;
    void open(QString);
    void save(QString) const;
	friend ostream& operator <<(ostream& flux, const Groupe& g);
};
#endif

