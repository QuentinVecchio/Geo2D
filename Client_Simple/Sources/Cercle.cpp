#include "../Headers/Cercle.h"


Cercle::Cercle(const Point p, const float r, const Couleur::Couleurs c):Figure(p,c)
{
	this->rayon = r;
}

Cercle::Cercle(const Cercle& c)
{
    this->rayon = c.getRayon();
    this->setP1(c.getP1());
    this->setC(this->getC());
}

float Cercle::getRayon() const
{
	return this->rayon;
}

void Cercle::setRayon(const float r)
{
	this->rayon = r;
}

void Cercle::translation(const Point p)
{
    this->getP1().setX(getP1().getX() + p.getX());
    this->getP1().setY(getP1().getY() + p.getY());
}


void Cercle::homothetie(const Point centre, float rapport)
{
    cout << p << "/" << rapport;
}

QDomElement Cercle::toXml(QDomDocument * dom) const
{
    //Création de la balise cercle
    QDomElement nom = dom->createElement("cercle");
    //Création de la balise rayon
    QDomElement rayon = dom->createElement("rayon");
    QString a;
    a.setNum(this->getRayon());
    QDomText r = dom->createTextNode(a);
    rayon.appendChild(r);
    nom.appendChild(rayon);
    //Création de la balise point
    QDomElement point = this->getP1().toXml(dom);
    nom.appendChild(point);
    //Création de la balise couleur
    QDomElement couleur = dom->createElement("couleur");
    QDomText c = dom->createTextNode(Couleur::getCouleur(this->getC()));
    couleur.appendChild(c);
    nom.appendChild(couleur);
    return nom;
}

Cercle* Cercle::copy() const
{
    return new Cercle(*this);
}

void Cercle::afficher(ostream& flux) const
{
    flux << "Cercle[ Point[ x = " << this->getP1().getX() << ", y = " << this->getP1().getY() << "], " << " Rayon = " << this->rayon << ", couleur = " << Couleur::getCouleur(this->getC()).toStdString() << "] " << endl;
}

ostream& operator <<(ostream& flux, const Cercle& c)
{
	c.afficher(flux);
	return flux;
}
