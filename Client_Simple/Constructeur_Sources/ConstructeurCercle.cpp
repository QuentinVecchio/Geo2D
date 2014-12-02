#include "../Constructeur_Headers/ConstructeurCercle.h"

ConstructeurCercle::ConstructeurCercle(ConstructeurCOR *s) : ConstructeurCOR(s)
{

}

Figure* ConstructeurCercle::resoudre1(const QDomNode *d) const
{
    QDomElement objet = d->toElement();
    if(objet.tagName() == "cercle")
    {
        QDomElement elt;
        float x = 0, y = 0, rayon = 0;
        QString couleur = "BLACK";
        QDomNode n = objet.firstChild();
        while(!n.isNull())
        {
            if(n.toElement().tagName() == "point")
            {
                QDomNode p = n.toElement().firstChild();
                while(!p.isNull())
                {
                    elt = p.toElement();
                    if(p.toElement().tagName() == "X")
                    {
                        x = elt.text().toFloat();
                    }
                    else if(p.toElement().tagName() == "Y")
                    {
                        y = elt.text().toFloat();
                    }
                    p = p.nextSibling();
               }
            }
            else if(n.toElement().tagName() == "rayon")
            {
                elt = n.toElement();
                rayon = elt.text().toFloat();
            }
            else if(n.toElement().tagName() == "couleur")
            {
                elt = n.toElement();
                couleur = elt.text();
            }
            n = n.nextSibling();
        }
        Cercle *c = new Cercle(new Point(x,y), rayon, Couleur::getNameCouleur(couleur));
        return c;
    }
    else
    {
        return NULL;
    }
}
