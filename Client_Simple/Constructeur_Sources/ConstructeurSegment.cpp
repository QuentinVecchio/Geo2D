#include "../Constructeur_Headers/ConstructeurSegment.h"

ConstructeurSegment::ConstructeurSegment(ConstructeurCOR *s) : ConstructeurCOR(s)
{

}

Figure * ConstructeurSegment::resoudre1(const QDomNode *d) const
{
    QDomElement objet = d->toElement();
    if(objet.tagName() == "segment")
    {
        float x1 = 0, y1 = 0, x2 = 0, y2 = 0;
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
                        if(x1 == 0)
                            x1 = n.toElement().toText().data().toFloat();
                        else
                            x2 = n.toElement().toText().data().toFloat();

                    }
                    else if(p.toElement().tagName() == "Y")
                    {
                        if(y1 == 0)
                            y1 = n.toElement().toText().data().toFloat();
                        else
                            y2 = n.toElement().toText().data().toFloat();
                    }
                    p = p.nextSibling();
                }
            }
            else if(n.toElement().tagName() == "couleur")
            {
                couleur = n.toElement().toText().data();
            }
            n = n.nextSibling();
        }
        Segment *s = new Segment(new Point(x1,y1), new Point(x2,y2),Couleur::getNameCouleur(couleur));
        return s;
    }
    else
    {
        return NULL;
    }
}
