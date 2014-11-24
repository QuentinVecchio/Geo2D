#include "../Headers/Ellipse.h"

Ellipse::Ellipse(const Point *p, const Point *p2,const float r, const Couleur::Couleurs c):Cercle(p,r,c)
{
    if(r < 0){
        ExceptionGeo2D *e = new ExceptionGeo2D("Erreur, le rayon d'une ellipse doit etre strictement superieur a 0");
        cout << e->get_erreur() << endl;
        exit(1);
    }
    else{
        this->p2 = p2->copy();
    }
}

Ellipse::Ellipse(const Ellipse& e):Cercle(e.getP1(), e.getRayon(), e.getC())
{
    this->p2 = e.getP2();
}

Point *Ellipse::getP2()const{
    return this->p2;
}

void Ellipse::setP2(const Point *p){
    this->p2 = p->copy();
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
        if(centre == *this->getP1()){
            this->p2->setX(this->getP1()->getX() + rapport);
            this->p2->setY(this->getP1()->getY() + rapport);
            this->setRayon(this->getRayon() * rapport);
        }
        else if(centre == *this->p2){
            this->setP1(Point(this->p2->getX() - rapport, this->p2->getY() - rapport).copy());
            this->setRayon(this->getRayon() * rapport);
        }
    }
}

void Ellipse::rotation(const Point * origine, double angle){
    if (origine == *this->getP1()){
        float X2 = this->p2->getX() - origine->getX();
        float Y2 = this->p2->getY() - origine->getY();
        float newx2 = origine->getX() + X2 * cos(angle) - Y2 * sin(angle);
        float newy2 = origine->getY() + X2 * sin(angle) + Y2 * cos(angle);
        this->p2->setX(newx2);
        this->p2->setY(newy2);
    }
    else if (origine == *this->p2){
        float X = this->getP1()->getX() - origine->getX();
        float Y = this->getP1()->getY() - origine->getY();
        float newx = origine->getX() + X * cos(angle) - Y * sin(angle);
        float newy = origine->getY() + X * sin(angle) + Y * cos(angle);
        this->setP1(Point(newx, newy).copy());
    }
    else if(origine == Point(0.0, 0.0)){
        float X = this->getP1()->getX() - origine->getX();
        float Y = this->getP1()->getY() - origine->getY();
        float newx = origine->getX() + X * cos(angle) - Y * sin(angle);
        float newy = origine->getY() + X * sin(angle) + Y * cos(angle);
        this->setP1(Point(newx, newy).copy());

        float X2 = this->p2->getX() - origine->getX();
        float Y2 = this->p2->getY() - origine->getY();
        float newx2 = origine->getX() + X2 * cos(angle) - Y2 * sin(angle);
        float newy2 = origine->getY() + X2 * sin(angle) + Y2 * cos(angle);
        this->p2->setX(newx2);
        this->p2->setY(newy2);
    }
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
    //Création de la balise point
    QDomElement point = this->getP1()->toXml(dom);
    nom.appendChild(point);
    //Création de la balise point
    QDomElement point2 = this->getP2()->toXml(dom);
    nom.appendChild(point2);
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
    flux << "Ellipse[ Point[ x = " << this->getP1()->getX() << ", y = " << this->getP1()->getY() << "], Point[ x = " << this->getP2()->getX() << ", y = " << this->getP2()->getY() << "] " << " Rayon = " << this->getRayon() << ", couleur = " << Couleur::getCouleur(this->getC()).toStdString() << "] " << endl;
}

ostream& operator <<(ostream& flux, const Ellipse& c)
{
    c.afficher(flux);
    return flux;
}

Ellipse::~Ellipse(){
    delete this->getP2();
}
