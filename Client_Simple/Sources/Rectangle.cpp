#include "../Headers/Rectangle.h"
#include "../Headers/Segment.h"

Rectangle::Rectangle(const Point *p1, const Point *p2, const Point *p3, const Point *p4,const Couleur::Couleurs c) :Figure(p1,c)
{
    if(!(estRectangle(p1, p2, p3, p4))){
        ExceptionGeo2D *e = new ExceptionGeo2D("Erreur, ceci n'est pas un rectangle");
        cout << e->get_erreur() << endl;
        exit(1);
    }
    else{
        this->p2 = p2->copy();
        this->p3 = p3->copy();
        this->p4 = p4->copy();
    }
}

Rectangle::Rectangle(const Rectangle &ca) :Figure(ca.getP1()->copy(),ca.getC())
{
    this->p2 = ca.getP2();
    this->p3 = ca.getP3();
    this->p4 = ca.getP4();
}

Point *Rectangle::getP2() const
{
    return this->p2;
}

Point *Rectangle::getP3() const
{
    return this->p3;
}

Point *Rectangle::getP4() const
{
    return this->p4;
}

void Rectangle::setP2(const Point *p)
{
    this->p2 = p->copy();
}

void Rectangle::setP3(const Point *p)
{
    this->p3 = p->copy();
}

void Rectangle::setP4(const Point *p)
{
    this->p4 = p->copy();
}

float Rectangle::getAire()const{
    Segment *longueur = new Segment(this->getP2(), this->getP3(), this->getC());
    Segment *largeur = new Segment(this->getP1(), this->getP2(), this->getC());
    return longueur->getLongueur() * largeur->getLongueur();
}

Point *Rectangle::getMilieu()const{
    Segment *diag = new Segment(this->getP1(), this->getP3(), this->getC());
    double newxdiag = (diag->getP1()->getX() + diag->getP2()->getX()) / 2;
    double newydiag = (diag->getP1()->getY() + diag->getP2()->getY()) / 2;
    Point *milieu = new Point(newxdiag, newydiag);
    return milieu;
}

void Rectangle::translation(const Point *p)
{
    this->setP1(Point(this->getP1()->getX() + p->getX(), this->getP1()->getY() + p->getY()).copy());
    this->p2->setX(p2->getX() + p->getX());
    this->p2->setY(p2->getY() + p->getY());
    this->p3->setX(p3->getX() + p->getX());
    this->p3->setY(p3->getY() + p->getY());
    this->p4->setX(p4->getX() + p->getX());
    this->p4->setY(p4->getY() + p->getY());
}

void Rectangle::rotation(const Point *origine, double angle)
{
    if (origine == *this->getP1()){
        double X2 = this->getP2()->getX() - origine->getX();
        double Y2 = this->getP2()->getY() - origine->getY();
        double newx2 = origine->getX() + X2 * cos(angle) - Y2 * sin(angle);
        double newy2 = origine->getY() + X2 * sin(angle) + Y2 * cos(angle);
        this->getP2()->setX(newx2);
        this->getP2()->setY(newy2);

        double X3 = this->getP3()->getX() - origine->getX();
        double Y3 = this->getP3()->getY() - origine->getY();
        double newx3 = origine->getX() + X3 * cos(angle) - Y3 * sin(angle);
        double newy3 = origine->getY() + X3 * sin(angle) + Y3 * cos(angle);
        this->p3->setX(newx3);
        this->p3->setY(newy3);

        double X4 = this->getP4()->getX() - origine->getX();
        double Y4 = this->getP4()->getY() - origine->getY();
        double newx4 = origine->getX() + X4 * cos(angle) - Y4 * sin(angle);
        double newy4 = origine->getY() + X4 * sin(angle) + Y4 * cos(angle);
        this->getP4()->setX(newx4);
        this->getP4()->setY(newy4);
    }
    else if (origine == *this->getP2()){
        double X = this->getP1()->getX() - origine->getX();
        double Y = this->getP1()->getY() - origine->getY();
        double newx = origine->getX() + X * cos(angle) - Y * sin(angle);
        double newy = origine->getY() + X * sin(angle) + Y * cos(angle);
        this->setP1(Point(newx, newy).copy());

        double X3 = this->p3->getX() - origine->getX();
        double Y3 = this->p3->getY() - origine->getY();
        double newx3 = origine->getX() + X3 * cos(angle) - Y3 * sin(angle);
        double newy3 = origine->getY() + X3 * sin(angle) + Y3 * cos(angle);
        this->p3->setX(newx3);
        this->p3->setY(newy3);

        double X4 = this->getP4()->getX() - origine->getX();
        double Y4 = this->getP4()->getY() - origine->getY();
        double newx4 = origine->getX() + X4 * cos(angle) - Y4 * sin(angle);
        double newy4 = origine->getY() + X4 * sin(angle) + Y4 * cos(angle);
        this->getP4()->setX(newx4);
        this->getP4()->setY(newy4);
    }
    else if(origine == *this->p3){
        double X = this->getP1()->getX() - origine->getX();
        double Y = this->getP1()->getY() - origine->getY();
        double newx = origine->getX() + X * cos(angle) - Y * sin(angle);
        double newy = origine->getY() + X * sin(angle) + Y * cos(angle);
        this->setP1(Point(newx, newy).copy());

        double X2 = this->p2->getX() - origine->getX();
        double Y2 = this->p2->getY() - origine->getY();
        double newx2 = origine->getX() + X2 * cos(angle) - Y2 * sin(angle);
        double newy2 = origine->getY() + X2 * sin(angle) + Y2 * cos(angle);
        this->getP2()->setX(newx2);
        this->getP2()->setY(newy2);

        double X4 = this->getP4()->getX() - origine->getX();
        double Y4 = this->getP4()->getY() - origine->getY();
        double newx4 = origine->getX() + X4 * cos(angle) - Y4 * sin(angle);
        double newy4 = origine->getY() + X4 * sin(angle) + Y4 * cos(angle);
        this->getP4()->setX(newx4);
        this->getP4()->setY(newy4);
    }
    else if(origine == *this->getP4()){
        double X = this->getP1()->getX() - origine->getX();
        double Y = this->getP1()->getY() - origine->getY();
        double newx = origine->getX() + X * cos(angle) - Y * sin(angle);
        double newy = origine->getY() + X * sin(angle) + Y * cos(angle);
        this->setP1(Point(newx, newy).copy());

        double X2 = this->p2->getX() - origine->getX();
        double Y2 = this->p2->getY() - origine->getY();
        double newx2 = origine->getX() + X2 * cos(angle) - Y2 * sin(angle);
        double newy2 = origine->getY() + X2 * sin(angle) + Y2 * cos(angle);
        this->getP2()->setX(newx2);
        this->getP2()->setY(newy2);

        double X3 = this->p3->getX() - origine->getX();
        double Y3 = this->p3->getY() - origine->getY();
        double newx3 = origine->getX() + X3 * cos(angle) - Y3 * sin(angle);
        float newy3 = origine->getY() + X3 * sin(angle) + Y3 * cos(angle);
        this->p3->setX(newx3);
        this->p3->setY(newy3);
    }
    else{
        double X = this->getP1()->getX() - origine->getX();
        double Y = this->getP1()->getY() - origine->getY();
        double newx = origine->getX() + X * cos(angle) - Y * sin(angle);
        double newy = origine->getY() + X * sin(angle) + Y * cos(angle);
        this->setP1(Point(newx, newy).copy());

        double X2 = this->getP2()->getX() - origine->getX();
        double Y2 = this->getP2()->getY() - origine->getY();
        double newx2 = origine->getX() + X2 * cos(angle) - Y2 * sin(angle);
        double newy2 = origine->getY() + X2 * sin(angle) + Y2 * cos(angle);
        this->getP2()->setX(newx2);
        this->getP2()->setY(newy2);

        double X3 = this->p3->getX() - origine->getX();
        double Y3 = this->p3->getY() - origine->getY();
        double newx3 = origine->getX() + X3 * cos(angle) - Y3 * sin(angle);
        float newy3 = origine->getY() + X3 * sin(angle) + Y3 * cos(angle);
        this->p3->setX(newx3);
        this->p3->setY(newy3);

        double X4 = this->getP4()->getX() - origine->getX();
        double Y4 = this->getP4()->getY() - origine->getY();
        double newx4 = origine->getX() + X4 * cos(angle) - Y4 * sin(angle);
        double newy4 = origine->getY() + X4 * sin(angle) + Y4 * cos(angle);
        this->getP4()->setX(newx4);
        this->getP4()->setY(newy4);
    }
}

void Rectangle::homothetie(const Point *centre, float rapport)
{
    if(rapport == 1){
        cout << "Les points restent invariants avec un rapport de 1" << endl;
    }
    else{
        if(centre == *this->getP1()){
            this->getP2()->setY(this->getP2()->getY() + rapport);
            this->getP3()->setX(this->getP3()->getX() + rapport);
            this->getP3()->setY(this->getP3()->getY() + rapport);
            this->getP4()->setX(this->getP4()->getX() + rapport);
        }
        else if(centre == *this->getP2()){
            this->setP1(Point(this->getP1()->getX(), this->getP1()->getY() - rapport).copy());
            this->getP3()->setX(this->getP3()->getX() + rapport);
            this->getP4()->setX(this->getP4()->getX() + rapport);
            this->getP4()->setY(this->getP4()->getY() - rapport);
        }
        else if(centre == *this->getP3()){
            this->setP1(Point(this->getP1()->getX() - rapport, this->getP1()->getY() - rapport).copy());
            this->getP2()->setX(this->getP2()->getX() - rapport);
            this->getP4()->setY(this->getP4()->getY() - rapport);
        }
        else if(centre == *this->getP4()){
            this->setP1(Point(this->getP1()->getX() - rapport, this->getP1()->getY()).copy());
            this->getP2()->setX(this->getP2()->getX() - rapport);
            this->getP2()->setY(this->getP2()->getY() + rapport);
            this->getP3()->setY(this->getP3()->getY() + rapport);
        }
        else if(centre == Point(0.0, 0.0)){
            this->getP1()->setX(this->getP1()->getX() * rapport);
            this->getP1()->setY(this->getP1()->getY() * rapport);
            this->getP2()->setX(this->getP2()->getX() * rapport);
            this->getP2()->setY(this->getP2()->getY() * rapport);
            this->getP3()->setX(this->getP3()->getX() * rapport);
            this->getP3()->setY(this->getP3()->getY() * rapport);
            this->getP4()->setX(this->getP4()->getX() * rapport);
            this->getP4()->setY(this->getP4()->getY() * rapport);
        }
    }
}

bool Rectangle::estRectangle(const Point *p1, const Point *p2, const Point *p3, const Point *p4){
    Segment *s1 = new Segment(p1, p2, this->getC());
    Segment *s2 = new Segment(p2, p3, this->getC());
    Segment *s3 = new Segment(p3, p4, this->getC());
    Segment *s4 = new Segment(p4, p1, this->getC());
    return s1->getLongueur() == s3->getLongueur() && s2->getLongueur() == s4->getLongueur() ;
}

Rectangle* Rectangle::copy() const
{
    return new Rectangle(*this);
}

QDomElement Rectangle::toXml(QDomDocument * dom) const
{
    //Création de la balise triangle
    QDomElement nom = dom->createElement("rectangle");
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

void Rectangle::afficher(ostream& flux) const
{
    flux << "Rectangle[ Point[ x = " << this->getP1()->getX() << ", y = " << this->getP1()->getY() << "], Point[ x = " << this->getP2()->getX() << ", y = " << this->getP2()->getY() << "], Point[ x = " << this->getP3()->getX() << ", y = " << this->getP3()->getY() << "]" << "], Point[ x = " << this->getP4()->getX() << ", y = " << this->getP4()->getY() << "]" << ", couleur = " << Couleur::getCouleur(this->getC()).toStdString() << "]" << endl;
}

ostream& operator <<(ostream& flux, const Rectangle& ca)
{
    ca.afficher(flux);
    return flux;
}

Rectangle::~Rectangle(){
    delete this->getP1();
    delete this->p2;
    delete this->p3;
    delete this->p4;
}


