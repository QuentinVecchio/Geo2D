#include "../Headers/Groupe.h"
#include <algorithm>

Groupe::Groupe(const Couleur::Couleurs c){
    this->c = c;
    this->dom = new QDomDocument();
}

Groupe::Groupe(const vector<Figure*> groupe, const Couleur::Couleurs c)
{
    this->c = c;
    this->v = groupe;
}

Groupe::Groupe(const Groupe& g)
{
    this->v = g.getV();
}

void Groupe::add(Figure *f)
{
    // on applique la couleur du groupe à toutes ses pièces
    f->setC(this->c);
    this->v.push_back(f);
}

float Groupe::getAire()const{
    float res = 0.0;
    for (int i = 0; i < v.size(); i++)
    {
        res += this->v[i]->getAire();
    }
    return res;
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

void Groupe::translation(const Point *p)
{
	for (int i = 0; i < v.size(); i++)
	{
		this->v[i]->translation(p);
	}
}

void Groupe::rotation(const Point *origine, double angle)
{
    for (int i = 0; i < v.size(); i++)
    {
        this->v[i]->rotation(origine, angle);
    }
}

void Groupe::homothetie(const Point *centre,  float rapport)
{
    for (int i = 0; i < v.size(); i++)
    {
        this->v[i]->homothetie(centre, rapport);
    }
}

Groupe* Groupe::copy() const
{
    return new Groupe(*this);
}

QDomElement Groupe::toXml(QDomDocument *doc) const
{
    //Création de la balise groupe
    QDomElement nom = doc->createElement("groupe");
    for(int i=0;i<this->nbElements();i++)
    {
        nom.appendChild(this->v[i]->toXml(dom));
    }
    //Création de la balise couleur
    QDomElement couleur = dom->createElement("couleur");
    QDomText c = dom->createTextNode(Couleur::getCouleur(this->getC()));
    couleur.appendChild(c);
    nom.appendChild(couleur);
    return nom;
}

QString Groupe::toStringXml() const
{
    //Création du bloc principal Dessin
    this->dom->clear();
    QDomElement write_elem = dom->createElement("dessin"); // On crée un QDomElement qui a comme nom de balise "dessin".
    dom->appendChild(write_elem);
    //Création de tous les blocs figure
    for(int i=0;i<this->nbElements();i++)
    {
        write_elem.appendChild(this->v[i]->toXml(dom));
    }
    QString s = dom->toString();
    s.replace(" ","");
    s.replace("\t","");
    s.replace("\r","");
    s.replace("\n","");
    return s;
}

void Groupe::open(QString s)
{
    QFile *f = new QFile(s);
    this->dom = new QDomDocument();
    if(!f->open(QIODevice::ReadOnly))
    {
        cout << "Erreur lecture de fichier." << endl;
        return;
    }
    if (!this->dom->setContent(f))
    {
        //Appel des constructeurs
        ConstructeurCOR *COR = new ConstructeurCercle(NULL);
        COR = new ConstructeurSegment(COR);
        COR = new ConstructeurPolygone(COR);
        COR = new ConstructeurTriangle(COR);
        COR = new ConstructeurGroupe(COR);

        //Initialisation XML
        QDomElement racine = this->dom->documentElement();
        QDomNode *noeud = new QDomNode(racine.firstChild());//Recursive
        if(racine.nodeName() == "dessin")
        {
            while(!noeud->isNull())
            {
                //On envoie le noeud à l'expert
                Figure *f = COR->resoudre(noeud);
                if(f == NULL)
                {
                    cout << "Erreur figure inconnu, fichier corrompu." << endl;
                    return;
                }
                else
                {
                    this->add(f);
                    *noeud = noeud->nextSibling();//On passe à l'objet suivant
                }
            }
        }
        f->close();
    }
}

void Groupe::save(QString s) const
{
    this->toStringXml();
    QFile *f = new QFile(s);
    QTextStream out;
    if (!f->open(QIODevice::WriteOnly)) // ouverture du fichier de sauvegarde
    {
        cout << "Erreur de sauvegarde." << endl;
        return;
    }
    out.setDevice(f);
    this->dom->save(out,2);
    f->close();
}

class AffObjet{
private:
	ostream& flux;
public:
    AffObjet(ostream& flux) :flux(flux){}
	void operator () (Figure* f){
		flux << *f << endl;
	}

};

ostream& operator <<(ostream& flux, const Groupe& g){
	AffObjet aff(flux);
    cout << "Groupe[ " << endl;
	for_each(g.v.begin(), g.v.end(), AffObjet(flux));
    cout << "]" << endl;
	return flux;
}

Groupe::~Groupe(){
    int i;
    for (i = 0; i < v.size(); i++) {
        delete this->v[i];
    }
}

