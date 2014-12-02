#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../Headers/Figure.h"
class Rectangle : public Figure{
private:
    Point *p2;
    Point *p3;
    Point *p4;
public:
    Rectangle(const Point *p1, const Point *p2, const Point *p3, const Point *p4, const Couleur::Couleurs c);
    Rectangle(const Rectangle &ca);
    ~Rectangle();

    Point *getP2()const;
    void setP2(const Point *p);

    Point *getP3()const;
    void setP3(const Point *p);

    Point *getP4()const;
    void setP4(const Point *p);

    float getAire() const;
    Point *getMilieu()const;

    void translation(const Point *p);
    void rotation(const Point *origine, double angle);
    void homothetie(const Point *centre, float rapport);

    bool estRectangle(const Point *p1, const Point *p2, const Point *p3, const Point *p4);

    Rectangle* copy() const;
    QDomElement toXml(QDomDocument *) const;
    void afficher(ostream& flux) const;
    friend ostream& operator <<(ostream& flux, const Rectangle& ca);
};

#endif // RECTANGLE_Hs
