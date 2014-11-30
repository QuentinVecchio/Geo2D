#include "../Constructeur_Headers/ConstructeurGroupe.h"

ConstructeurGroupe::ConstructeurGroupe(ConstructeurCOR *s) : ConstructeurCOR(s)
{

}

Figure *ConstructeurGroupe::resoudre1(const QDomNode *d) const
{
    QDomNode *noeud = new QDomNode(d->firstChild());

    //Appel des constructeurs
    ConstructeurCOR *COR = new ConstructeurCercle(NULL);
    COR = new ConstructeurSegment(COR);
    COR = new ConstructeurPolygone(COR);
    COR = new ConstructeurTriangle(COR);
    COR = new ConstructeurGroupe(COR);

    Groupe *g = new Groupe(Couleur::BLACK);
    while(!noeud->isNull())
    {
            //On envoie le noeud à l'expert
            Figure *f = COR->resoudre(noeud);
            if(f == NULL)
            {
                cout << "Erreur figure inconnu, fichier corrompu." << endl;
                return NULL;
            }
            else
            {
                g->add(f);
                *noeud = noeud->nextSibling();//On passe à l'objet suivant
            }
    }
    return g;
}
