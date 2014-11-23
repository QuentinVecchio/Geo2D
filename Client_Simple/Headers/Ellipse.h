#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "../Headers/Ellipse.h"
#include "../Headers/Cercle.h"

class Ellipse : public Cercle{
private:
    Point *p2;
public:
    Ellipse(const Point *p, const Point *p2, const float r, const Couleur::Couleurs c);
    Ellipse(const Ellipse& e);
    ~Ellipse();

    Point *getP2() const;
    void setP2(const Point *p);

    float getAire()const;

    void rotation(const Point *origine, double angle);
    void translation(const Point *p);
    void homothetie(const Point *centre,  float rapport);

    QDomElement toXml(QDomDocument *) const;
    Ellipse* copy() const;
    void afficher(ostream& flux) const;
    friend ostream& operator <<(ostream& flux, const Ellipse& e);
};

#endif // ELLIPSE_H
