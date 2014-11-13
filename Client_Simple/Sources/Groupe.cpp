#include "Headers/Groupe.h"
#include <algorithm>

Groupe::Groupe()
{

}

Groupe::Groupe(const vector<Figure*> polygone)
{
	this->v = polygone;
}

Groupe::Groupe(const Groupe& g)
{
    this->v = g.getV();
}

Groupe::~Groupe()
{

}

void Groupe::add(Figure *f)
{
    this->v.push_back(f);
}

vector<Figure*> Groupe::getV() const
{
    return this->v;
}

Figure* Groupe::getFigure(const int i) const
{
    if (i < 0 || i >= nbElements())
    {
		abort();
	}
    else
    {
        return v[i];
	}
}

int Groupe::nbElements()const
{
	return this->v.size();
}

void Groupe::translation(const Point p)
{
	for (int i = 0; i < v.size(); i++)
	{
		this->v[i]->translation(p);
	}
}

void Groupe::rotation()
{
    for (int i = 0; i < v.size(); i++)
    {
        this->v[i]->rotation();
    }
}

void Groupe::homothetie()
{
    for (int i = 0; i < v.size(); i++)
    {
        this->v[i]->homothetie();
    }
}

Groupe* Groupe::copy() const
{
    return new Groupe(*this);
}

QString Groupe::toXml() const
{
    QDomDocument *dom = new QDomDocument();
    QFile *file = new QFile("groupe.xml");
    QTextStream *out = new QTextStream();
    out->setDevice(file);
    if(!file->open(QIODevice::WriteOnly))// Si l'on n'arrive pas à ouvrir le fichier XML.
    {
       cout << "Erreur à l'ouverture du document XML, Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé" << endl;
       exit(1);
    }
    //Création du bloc principal Dessin
    //QDomElement docElem = dom->documentElement();
    QDomElement write_elem = dom->createElement("dessin"); // On crée un QDomElement qui a comme nom de balise "dessin".
    dom->appendChild(write_elem);
    //Création de tous les blocs figure
    for(int i=0;i<this->nbElements();i++)
    {
        write_elem.appendChild(this->v[i]->toXml(dom));
    }

    return dom->toString();
}

class AffObjet{
private:
	ostream& flux;
public:
	AffObjet(ostream& flux) :flux(flux){};
	void operator () (Figure* f){
		flux << *f << endl;
	}

};

ostream& operator <<(ostream& flux, const Groupe& g){
	AffObjet aff(flux);
	for_each(g.v.begin(), g.v.end(), AffObjet(flux));
	return flux;
}

