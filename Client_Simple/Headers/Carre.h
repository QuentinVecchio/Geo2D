#ifndef CARRE_H
#define CARRE_H
#include "../Headers/Figure.h"
#include <QtXml>

class Carre : public Figure{
private:
    Point *p2;
    Point *p3;
    Point *p4;
public:
    Carre(const Point *p1, const Point *p2, const Point *p3, const Point *p4, const Couleur::Couleurs c);
    Carre(const Carre &ca);
    ~Carre();

    Point *getP2()const;
    void setP2(const Point *p);

    Point *getP3()const;
    void setP3(const Point *p);

    Point *getP4()const;
    void setP4(const Point *p);

    float getAire() const;

    void translation(const Point *p);
    void rotation(const Point *origine, double angle);
    void homothetie(const Point *centre, float rapport);

    bool estCarre(const Point *p1, const Point *p2, const Point *p3, const Point *p4);

    Carre* copy() const;
    QDomElement toXml(QDomDocument *) const;
    void afficher(ostream& flux) const;
    friend ostream& operator <<(ostream& flux, const Carre& ca);
};

#endif // CARRE_H
