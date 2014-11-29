#include "../Constructeur_Headers/ConstructeurEllipse.h"

ConstructeurEllipse::ConstructeurEllipse(ConstructeurCOR *s) : ConstructeurCOR(s)
{

}

Figure* ConstructeurEllipse::resoudre1(const QDomNode *d) const
{
    QDomElement objet = d->toElement();
    if(objet.tagName() == "ellipse")
    {
        float x = 0, y = 0, rayon = 0, hauteur = 0;
        QString couleur = "BLACK";
        QDomNode n = objet.firstChild();
        while(!n.isNull())
        {
            if(n.toElement().tagName() == "point")
            {
                QDomNode p = n.toElement().firstChild();
                while(!p.isNull())
                {
                    if(p.toElement().tagName() == "X")
                    {
                        x = n.toElement().toText().data().toFloat();
                    }
                    else if(p.toElement().tagName() == "Y")
                    {
                        y = n.toElement().toText().data().toFloat();
                    }
                    p = p.nextSibling();
               }
            }
            else if(n.toElement().tagName() == "rayon")
            {
                rayon = n.toElement().toText().data().toFloat();
            }
            else if(n.toElement().tagName() == "hauteur")
            {
                hauteur = n.toElement().toText().data().toFloat();
            }
            else if(n.toElement().tagName() == "couleur")
            {
                couleur = n.toElement().toText().data();
            }
            n = n.nextSibling();
        }
        Ellipse *c = new Ellipse(new Point(x,y), rayon, hauteur, Couleur::getNameCouleur(couleur));
        return c;
    }
    else
    {
        return NULL;
    }
}

