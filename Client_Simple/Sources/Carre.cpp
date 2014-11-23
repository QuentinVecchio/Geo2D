#include "../Headers/Carre.h"
#include "../Headers/Segment.h"

Carre::Carre(const Point *p1, const Point *p2, const Point *p3, const Point *p4,const Couleur::Couleurs c) :Figure(p1,c)
{
    if(!(estCarre(p1, p2, p3, p4))){
        ExceptionGeo2D *e = new ExceptionGeo2D("Erreur, ceci n'est pas un carre");
        cout << e->get_erreur() << endl;
        exit(1);
    }
    else{
        this->p2 = p2->copy();
        this->p3 = p3->copy();
        this->p4 = p4->copy();
    }
}

Carre::Carre(const Carre &ca) :Figure(ca.getP1()->copy(),ca.getC())
{
    this->p2 = ca.getP2();
    this->p3 = ca.getP3();
    this->p4 = ca.getP4();
}

Point *Carre::getP2() const
{
    return this->p2;
}

Point *Carre::getP3() const
{
    return this->p3;
}

Point *Carre::getP4() const
{
    return this->p4;
}

void Carre::setP2(const Point *p)
{
    this->p2 = p->copy();
}

void Carre::setP3(const Point *p)
{
    this->p3 = p->copy();
}

void Carre::setP4(const Point *p)
{
    this->p4 = p->copy();
}

float Carre::getAire()const{
    Segment *s = new Segment(this->getP1(), this->getP2(), this->getC());
    return pow(s->getLongueur(), 2);
}

void Carre::translation(const Point *p)
{
    this->setP1(Point(this->getP1()->getX() + p->getX(), this->getP1()->getY() + p->getY()).copy());
    this->p2->setX(p2->getX() + p->getX());
    this->p2->setY(p2->getY() + p->getY());
    this->p3->setX(p3->getX() + p->getX());
    this->p3->setY(p3->getY() + p->getY());
    this->p4->setX(p4->getX() + p->getX());
    this->p4->setY(p4->getY() + p->getY());
}

void Carre::rotation(const Point *origine, double angle)
{
    if (origine == *this->getP1()){
        float X2 = this->p2->getX() - origine->getX();
        float Y2 = this->p2->getY() - origine->getY();
        float newx2 = origine->getX() + X2 * cos(angle) - Y2 * sin(angle);
        float newy2 = origine->getY() + X2 * sin(angle) + Y2 * cos(angle);
        this->p2->setX(newx2);
        this->p2->setY(newy2);

        float X3 = this->p3->getX() - origine->getX();
        float Y3 = this->p3->getY() - origine->getY();
        float newx3 = origine->getX() + X3 * cos(angle) - Y3 * sin(angle);
        float newy3 = origine->getY() + X3 * sin(angle) + Y3 * cos(angle);
        this->p3->setX(newx3);
        this->p3->setY(newy3);

        float X4 = this->p4->getX() - origine->getX();
        float Y4 = this->p4->getY() - origine->getY();
        float newx4 = origine->getX() + X4 * cos(angle) - Y4 * sin(angle);
        float newy4 = origine->getY() + X4 * sin(angle) + Y4 * cos(angle);
        this->p4->setX(newx4);
        this->p4->setY(newy4);
    }
    else if (origine == *this->p2){
        float X = this->getP1()->getX() - origine->getX();
        float Y = this->getP1()->getY() - origine->getY();
        float newx = origine->getX() + X * cos(angle) - Y * sin(angle);
        float newy = origine->getY() + X * sin(angle) + Y * cos(angle);
        this->setP1(Point(newx, newy).copy());

        float X3 = this->p3->getX() - origine->getX();
        float Y3 = this->p3->getY() - origine->getY();
        float newx3 = origine->getX() + X3 * cos(angle) - Y3 * sin(angle);
        float newy3 = origine->getY() + X3 * sin(angle) + Y3 * cos(angle);
        this->p3->setX(newx3);
        this->p3->setY(newy3);

        float X4 = this->p4->getX() - origine->getX();
        float Y4 = this->p4->getY() - origine->getY();
        float newx4 = origine->getX() + X4 * cos(angle) - Y4 * sin(angle);
        float newy4 = origine->getY() + X4 * sin(angle) + Y4 * cos(angle);
        this->p4->setX(newx4);
        this->p4->setY(newy4);
    }
    else if(origine == *this->p3){
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

        float X4 = this->p4->getX() - origine->getX();
        float Y4 = this->p4->getY() - origine->getY();
        float newx4 = origine->getX() + X4 * cos(angle) - Y4 * sin(angle);
        float newy4 = origine->getY() + X4 * sin(angle) + Y4 * cos(angle);
        this->p4->setX(newx4);
        this->p4->setY(newy4);
    }
    else if(origine == *this->p4){
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

        float X3 = this->p3->getX() - origine->getX();
        float Y3 = this->p3->getY() - origine->getY();
        float newx3 = origine->getX() + X3 * cos(angle) - Y3 * sin(angle);
        float newy3 = origine->getY() + X3 * sin(angle) + Y3 * cos(angle);
        this->p3->setX(newx3);
        this->p3->setY(newy3);
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

        float X3 = this->p3->getX() - origine->getX();
        float Y3 = this->p3->getY() - origine->getY();
        float newx3 = origine->getX() + X3 * cos(angle) - Y3 * sin(angle);
        float newy3 = origine->getY() + X3 * sin(angle) + Y3 * cos(angle);
        this->p3->setX(newx3);
        this->p3->setY(newy3);

        float X4 = this->p4->getX() - origine->getX();
        float Y4 = this->p4->getY() - origine->getY();
        float newx4 = origine->getX() + X4 * cos(angle) - Y4 * sin(angle);
        float newy4 = origine->getY() + X4 * sin(angle) + Y4 * cos(angle);
        this->p4->setX(newx4);
        this->p4->setY(newy4);
    }
}

void Carre::homothetie(const Point *centre, float rapport)
{
    if(rapport == 1){
        cout << "Les points restent invariants avec un rapport de 1" << endl;
    }
    else{
        if(centre == *this->getP1()){
            this->p2->setX(this->p2->getX() * rapport);
            this->p2->setY(this->p2->getY() * rapport);
            this->p3->setX(this->p3->getX() * rapport);
            this->p3->setY(this->p3->getY() * rapport);
            this->p4->setX(this->p4->getX() * rapport);
            this->p4->setY(this->p4->getY() * rapport);
        }
        else if(centre == *this->p2){
            this->setP1(Point(this->getP1()->getX() * rapport, this->getP1()->getY() * rapport).copy());
            this->p3->setX(this->p3->getX() * rapport);
            this->p3->setY(this->p3->getY() * rapport);
            this->p4->setX(this->p4->getX() * rapport);
            this->p4->setY(this->p4->getY() * rapport);
        }
        else if(centre == *this->p3){
            this->setP1(Point(this->getP1()->getX() * rapport, this->getP1()->getY() * rapport).copy());
            this->p2->setX(this->p2->getX() * rapport);
            this->p2->setY(this->p2->getY() * rapport);
            this->p4->setX(this->p4->getX() * rapport);
            this->p4->setY(this->p4->getY() * rapport);
        }
        else if(centre == *this->p4){
            this->setP1(Point(this->getP1()->getX() * rapport, this->getP1()->getY() * rapport).copy());
            this->p2->setX(this->p2->getX() * rapport);
            this->p2->setY(this->p2->getY() * rapport);
            this->p3->setX(this->p3->getX() * rapport);
            this->p3->setY(this->p3->getY() * rapport);
        }
    }
}

bool Carre::estCarre(const Point *p1, const Point *p2, const Point *p3, const Point *p4){
    Segment *s1 = new Segment(p1, p2, this->getC());
    Segment *s2 = new Segment(p2, p3, this->getC());
    Segment *s3 = new Segment(p3, p4, this->getC());
    Segment *s4 = new Segment(p4, p1, this->getC());
    return s1->getLongueur() == s2->getLongueur() && s1->getLongueur() == s3->getLongueur() && s1->getLongueur() == s4->getLongueur() ;
}

Carre* Carre::copy() const
{
    return new Carre(*this);
}

QDomElement Carre::toXml(QDomDocument * dom) const
{
    //Création de la balise triangle
    QDomElement nom = dom->createElement("carre");
    //Création de la balise point1
    QDomElement point = this->getP1()->toXml(dom);
    nom.appendChild(point);
    //Création de la balise point2
    QDomElement point2 = this->getP2()->toXml(dom);
    nom.appendChild(point2);
    //Création de la balise point3
    QDomElement point3 = this->getP3()->toXml(dom);
    nom.appendChild(point3);
    //Création de la balise point4
    QDomElement point4 = this->getP4()->toXml(dom);
    nom.appendChild(point4);
    //Création de la balise couleur
    QDomElement couleur = dom->createElement("couleur");
    QDomText c = dom->createTextNode(Couleur::getCouleur(this->getC()));
    couleur.appendChild(c);
    nom.appendChild(couleur);
    return nom;
}

void Carre::afficher(ostream& flux) const
{
    flux << "Carre[ Point[ x = " << this->getP1()->getX() << ", y = " << this->getP1()->getY() << "], Point[ x = " << this->getP2()->getX() << ", y = " << this->getP2()->getY() << "], Point[ x = " << this->getP3()->getX() << ", y = " << this->getP3()->getY() << "]" << "], Point[ x = " << this->getP4()->getX() << ", y = " << this->getP4()->getY() << "]" << ", couleur = " << Couleur::getCouleur(this->getC()).toStdString() << "]" << endl;
}

ostream& operator <<(ostream& flux, const Carre& ca)
{
    ca.afficher(flux);
    return flux;
}

Carre::~Carre(){
    delete this->getP1();
    delete this->p2;
    delete this->p3;
    delete this->p4;
}

