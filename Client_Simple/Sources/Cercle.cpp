#include "../Headers/Cercle.h"


Cercle::Cercle(const Point *p, const float r, const Couleur::Couleurs c):Figure(p,c)
{
    if(r < 0){
        ExceptionGeo2D *e = new ExceptionGeo2D("Erreur, le rayon d'un cercle doit etre strictement superieur a 0");
        cout << e->get_erreur() << endl;
        exit(1);
    }
    else{
        this->rayon = r;
    }
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

float Cercle::getAire()const{
    float aire;
    float PI = 4.0 * atan(1.0);
    aire = pow(this->getRayon(), 2) * PI;
    return aire;
}

void Cercle::translation(const Point *p)
{
    this->setP1(Point(this->getP1()->getX() + p->getX(), this->getP1()->getY() + p->getY()).copy());
}


void Cercle::homothetie(const Point *centre, float rapport)
{
    if(rapport == 1){
        cout << "Le cercle reste invariant avec un rapport de 1" << endl;
    }
    else{
        this->getP1()->setX(centre->getX() + rapport);
        this->getP1()->setY(centre->getY() + rapport);
        this->setRayon(this->getRayon() * rapport);
    }
}

void Cercle::rotation(const Point * origine, double angle){
        float X = this->getP1()->getX() - origine->getX();
        float Y = this->getP1()->getY() - origine->getY();
        float newx = origine->getX() + X * cos(angle) - Y * sin(angle);
        float newy = origine->getY() + X * sin(angle) + Y * cos(angle);
        this->setP1(Point(newx, newy).copy());
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
    QDomElement point = this->getP1()->toXml(dom);
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
    flux << "Cercle[ Point[ x = " << this->getP1()->getX() << ", y = " << this->getP1()->getY() << "], " << " Rayon = " << this->rayon << ", couleur = " << Couleur::getCouleur(this->getC()).toStdString() << "] " << endl;
}

ostream& operator <<(ostream& flux, const Cercle& c)
{
	c.afficher(flux);
	return flux;
}

Cercle::~Cercle(){
    delete this->getP1();
}
