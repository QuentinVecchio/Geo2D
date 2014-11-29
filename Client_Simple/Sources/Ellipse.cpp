#include "../Headers/Ellipse.h"

Ellipse::Ellipse(const Point *p,const float r, const float h, const Couleur::Couleurs c):Cercle(p,r,c)
{
    if(r < 0 || h < 0)
    {
        ExceptionGeo2D *e = new ExceptionGeo2D("Erreur, le rayon d'une ellipse doit etre strictement superieur a 0");
        cout << e->get_erreur() << endl;
        exit(1);
    }
    else
    {
        this->hauteur = h;
    }
}

Ellipse::Ellipse(const Ellipse& e):Cercle(e.getP1(), e.getRayon(), e.getC())
{
    this->hauteur = e.getHauteur();
}

Ellipse::~Ellipse()
{

}

float Ellipse::getHauteur()const{
    return this->hauteur;
}

void Ellipse::setHauteur(const float h){
    if(h < 0)
    {
        ExceptionGeo2D *e = new ExceptionGeo2D("Erreur, le rayon d'une ellipse doit etre strictement superieur a 0");
        cout << e->get_erreur() << endl;
        exit(1);
    }
    else
    {
        this->hauteur = h;
    }
}

float Ellipse::getAire()const{
    float aire;
    float PI = 4.0 * atan(1.0);
    aire = pow(this->getRayon(), 2) * PI;
    return aire;
}

void Ellipse::translation(const Point *p)
{
    Cercle::translation(p);
}

void Ellipse::homothetie(const Point *centre, float rapport)
{
    if(rapport == 1){
        cout << "Les points restent invariants avec un rapport de 1" << endl;
    }
    else{
        this->setRayon(this->getRayon() * rapport);
        this->setHauteur(this->getHauteur() * rapport);
    }
}

void Ellipse::rotation(const Point * origine, double angle){
        float X = this->getP1()->getX() - origine->getX();
        float Y = this->getP1()->getY() - origine->getY();
        float newx = origine->getX() + X * cos(angle) - Y * sin(angle);
        float newy = origine->getY() + X * sin(angle) + Y * cos(angle);
        this->setP1(Point(newx, newy).copy());
}

QDomElement Ellipse::toXml(QDomDocument * dom) const
{
    //Création de la balise Ellipse
    QDomElement nom = dom->createElement("ellipse");
    //Création de la balise rayon
    QDomElement rayon = dom->createElement("rayon");
    QString a;
    a.setNum(this->getRayon());
    QDomText r = dom->createTextNode(a);
    rayon.appendChild(r);
    nom.appendChild(rayon);
    //Création de la balise hauteur
    QDomElement hauteur = dom->createElement("hauteur");
    a.setNum(this->getHauteur());
    QDomText h = dom->createTextNode(a);
    hauteur.appendChild(h);
    nom.appendChild(hauteur);
    //Création de la balise point
    QDomElement point = this->getP1()->toXml(dom);
    nom.appendChild(point);
    //Création de la balise couleur
    QDomElement couleur = dom->createElement("couleur");
    QDomText c = dom->createTextNode(Couleur::getCouleur(this->getC()));
    couleur.appendChild(c);
    nom.appendChild(couleur);
    return nom;
}

Ellipse* Ellipse::copy() const
{
    return new Ellipse(*this);
}

void Ellipse::afficher(ostream& flux) const
{
    flux << "Ellipse[ Point[ x = " << this->getP1()->getX() << ", y = " << this->getP1()->getY() << "]" << " Rayon = " << this->getRayon() << " Hauteur = " << this->getHauteur() << ", couleur = " << Couleur::getCouleur(this->getC()).toStdString() << "] " << endl;
}

ostream& operator <<(ostream& flux, const Ellipse& c)
{
    c.afficher(flux);
    return flux;
}
