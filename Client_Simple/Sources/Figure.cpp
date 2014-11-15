#include "../Headers/Figure.h"

Figure::Figure(const Point p1, const Couleur::Couleurs c)
{
	this->p1 = p1;
	this->c = c;
}

Figure::Figure(const Figure &f)
{
    this->c = f.getC();
    this->p1 = f.getP1();
}


Point Figure::getP1() const
{
	return this->p1;
}

Couleur::Couleurs Figure::getC() const
{
    return this->c;
}

void Figure::setP1(const Point p)
{
    this->p1 = p;
}

void Figure::setC(const Couleur::Couleurs c)
{
	this->c = c;
}

void Figure::afficher(ostream&) const
{

}

ostream& operator <<(ostream& flux, const Figure& f)
{
	f.afficher(flux);
	return flux;
}
