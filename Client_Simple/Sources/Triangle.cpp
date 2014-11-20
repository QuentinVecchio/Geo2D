#include "../Headers/Triangle.h"
#include "../Headers/Segment.h"

Triangle::Triangle(const Point *p1, const Point *p2, const Point *p3, const Couleur::Couleurs c) :Figure(p1,c)
{
    this->p2 = p2->copy();
    this->p3 = p3->copy();
}

Triangle::Triangle(const Triangle &t) :Figure(t.getP1()->copy(),t.getC())
{
    this->p2 = t.getP2();
    this->p3 = t.getP3();
}

Point *Triangle::getP2() const
{
    return this->p2;
}

Point *Triangle::getP3() const
{
    return this->p3;
}

void Triangle::setP2(const Point *p)
{
    this->p2 = p->copy();
}

void Triangle::setP3(const Point *p)
{
    this->p3 = p->copy();
}

float Triangle::getAire()const{
    float a,b,c,P,aire;
    // calcule des longueurs des cotés
    a = sqrt(pow((this->getP1()->getX() - this->p2->getX()), 2) + pow((this->getP1()->getY() - this->p2->getY()), 2));
    b = sqrt(pow((this->p2->getX() -  this->p3->getX()), 2) + pow((this->p2->getY() - this->p3->getY()), 2));
    c = sqrt(pow((this->p3->getX() - this->getP1()->getX()), 2) + pow((this->p3->getY() - this->getP1()->getY()), 2));
    //cout << a << " / " << b << " / " << c << endl;
    // application de la formule de Héron
    P = a + b + c ;
    P = (P / 2) ;
    aire = sqrt ( P * (P - a) * (P - b) * (P - c) );
    return aire;
}

void Triangle::translation(const Point *p)
{
    this->setP1(Point(this->getP1()->getX() + p->getX(), this->getP1()->getY() + p->getY()).copy());
    this->p2->setX(p2->getX() + p->getX());
    this->p2->setY(p2->getY() + p->getY());
    this->p3->setX(p3->getX() + p->getX());
    this->p3->setY(p3->getY() + p->getY());
}

void Triangle::rotation(const Point *origine, float angle)
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
    }
}

void Triangle::homothetie(const Point *centre, float rapport)
{
    if(rapport == 1){
        cout << "Les points restent invariants avec un rapport de 1" << endl;
    }
    else{

    }
}

Triangle* Triangle::copy() const
{
    return new Triangle(*this);
}

QDomElement Triangle::toXml(QDomDocument * dom) const
{
    //Création de la balise triangle
    QDomElement nom = dom->createElement("triangle");
    //Création de la balise point1
    QDomElement point = this->getP1()->toXml(dom);
    nom.appendChild(point);
    //Création de la balise point2
    QDomElement point2 = this->getP2()->toXml(dom);
    nom.appendChild(point2);
    //Création de la balise point3
    QDomElement point3 = this->getP3()->toXml(dom);
    nom.appendChild(point3);
    //Création de la balise couleur
    QDomElement couleur = dom->createElement("couleur");
    QDomText c = dom->createTextNode(Couleur::getCouleur(this->getC()));
    couleur.appendChild(c);
    nom.appendChild(couleur);
    return nom;
}

void Triangle::afficher(ostream& flux) const
{
    flux << "Triangle[ Point[ x = " << this->getP1()->getX() << ", y = " << this->getP1()->getY() << "], Point[ x = " << this->getP2()->getX() << ", y = " << this->getP2()->getY() << "], Point[ x = " << this->getP3()->getX() << ", y = " << this->getP3()->getY() << "]" << ", couleur = " << Couleur::getCouleur(this->getC()).toStdString() << "]" << endl;
}

ostream& operator <<(ostream& flux, const Triangle& t)
{
	t.afficher(flux);
	return flux;
}

Triangle::~Triangle(){
    delete this->getP1();
    delete this->p2;
    delete this->p3;
}
