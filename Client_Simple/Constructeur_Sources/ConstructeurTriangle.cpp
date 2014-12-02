#include "../Constructeur_Headers/ConstructeurTriangle.h"

ConstructeurTriangle::ConstructeurTriangle(ConstructeurCOR *s) : ConstructeurCOR(s)
{

}

Figure* ConstructeurTriangle::resoudre1(const QDomNode *d) const
{
    QDomElement objet = d->toElement();
    if(objet.tagName() == "triangle")
    {
        QDomElement elt;
        float x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
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
                        if(x1 == 0)
                            x1 = elt.text().toFloat();
                        else if(x1 != 0 && x2 == 0)
                            x2 = elt.text().toFloat();
                        else
                            x3 = elt.text().toFloat();

                    }
                    else if(p.toElement().tagName() == "Y")
                    {
                        if(y1 == 0)
                            y1 = elt.text().toFloat();
                        else if(y1 != 0 && y2 == 0)
                            y2 = elt.text().toFloat();
                        else
                            y3 = elt.text().toFloat();
                    }
                    p = p.nextSibling();
               }
            }
            else if(n.toElement().tagName() == "couleur")
            {
                elt = n.toElement();
                couleur = elt.text();
            }
            n = n.nextSibling();
        }
        Triangle *t = new Triangle(new Point(x1,y1), new Point(x2,y2),new Point(x3,y3), Couleur::getNameCouleur(couleur));
        return t;
    }
    else
    {
        return NULL;
    }
}
