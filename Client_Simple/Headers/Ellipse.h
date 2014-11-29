#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "../Headers/Ellipse.h"
#include "../Headers/Cercle.h"

class Ellipse : public Cercle{
private:
    //rayon devient largeur
    float hauteur;
public:
    Ellipse(const Point *p, const float r, const float h,const Couleur::Couleurs c);
    Ellipse(const Ellipse& e);
    ~Ellipse();

    float getHauteur() const;
    void setHauteur(const float h);

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
