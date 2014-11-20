#include "../Headers/Polygone.h"
#include <algorithm>

Polygone::Polygone(const Point *p, const Couleur::Couleurs c) : Figure(p,c){}

Polygone::Polygone(const Point *p, const Couleur::Couleurs c ,const vector<Segment*> polygone) : Figure(p,c)
{
    Segment *s = new Segment(polygone[0]->getP1(), polygone[0]->getP2(), c);
    this->v = polygone;
    this->v.insert(this->v.begin(),s);
}

Polygone::Polygone(const Polygone &p) : Figure(p.getP1(),p.getC())
{
    this->v = p.getV();
}

void Polygone::add(Segment *s)
{
    if(this->v.size() == 0)
    {
        Segment *s1 = new Segment(s->getP1(),s->getP2(),this->getC());
        this->v.push_back(s1);
    }
    else{
        this->v.push_back(s);
    }
}

vector<Segment*> Polygone::getV() const
{
    return this->v;
}

Segment* Polygone::getSegment(const int i) const
{
	if (i < 0 || i >= nbElements()){
		abort();
	}
	else{
        return v[i];
	}
}

int Polygone::nbElements() const
{
	return this->v.size();
}

void Polygone::translation(const Point *p)
{
	for (int i = 0; i < v.size(); i++)
	{
        this->v[i]->translation(p);
	}
}

void Polygone::rotation(const Point *origine, float angle)
{
    for (int i = 0; i < v.size(); i++)
    {
        this->v[i]->rotation(origine, angle);
    }
}

void Polygone::homothetie(const Point *centre, float rapport)
{
    for (int i = 0; i < v.size(); i++)
    {
        this->v[i]->homothetie(centre,rapport);
    }
}

Polygone* Polygone::copy() const
{
    return new Polygone(*this);
}

QDomElement Polygone::toXml(QDomDocument * dom) const
{
    //Création de la balise polygone
    QDomElement nom = dom->createElement("polygone");
    //Création des balises segments
    for(int i = 0;i<this->v.size();i++)
    {
        nom.appendChild(this->v[i]->toXml(dom));
    }
    return nom;
}

class AffObjet
{
private:
	ostream& flux;
public:
    AffObjet(ostream& flux) :flux(flux){}
	void operator () (Segment* s){
        flux <<  *s << endl;
	}

};

ostream& operator <<(ostream& flux, const Polygone& p)
{
	AffObjet aff(flux);
    cout << "Polygone[ " << endl;
    for_each(p.v.begin(), p.v.end(), AffObjet(flux));
    cout << "]" << endl;
	return flux;
}

Polygone::~Polygone(){
    int i;
    for (i = 0; i < v.size(); i++) {
        delete this->v[i];
    }
}
