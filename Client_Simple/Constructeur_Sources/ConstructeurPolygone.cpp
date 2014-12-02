#include "../Constructeur_Headers/ConstructeurPolygone.h"

ConstructeurPolygone::ConstructeurPolygone(ConstructeurCOR *s) : ConstructeurCOR(s)
{

}

Figure *ConstructeurPolygone::resoudre1(const QDomNode *d) const
{
    QDomElement objet = d->toElement();
    if(objet.tagName() == "polygone")
    {
        QDomElement elt;
        float x1 = 0, y1= 0, x2 = 0, y2 = 0;
        QString couleur = "BLACK";
        QDomNode n = objet.firstChild();
        Polygone *poly = new Polygone(new Point(0,0),Couleur::BLACK);
        while(!n.isNull())
        {
            if(n.toElement().tagName() == "point")
            {
                x1 = y1 = 0;
                QDomNode p1 = n.toElement().firstChild();
                while(!p1.isNull())
                {
                    if(p1.toElement().tagName() == "X")
                    {
                        x1 = elt.text().toFloat();
                    }
                    else if(p1.toElement().tagName() == "Y")
                    {
                        y1 = elt.text().toFloat();
                    }
                    p1 = p1.nextSibling();
                }
                poly->setP1(new Point(x1,y1));
            }
            if(n.toElement().tagName() == "segment")
            {
                x1 = 0;
                y1= 0;
                x2 = 0;
                y2 = 0;
                QDomNode s = n.toElement().firstChild();
                while(!s.isNull())
                {
                    if(s.toElement().tagName() == "point")
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
                }
                Segment *seg = new Segment(new Point(x1,y1), new Point(x2,y2),Couleur::getNameCouleur(couleur));
                poly->add(seg);
            }
            else if(n.toElement().tagName() == "couleur")
            {
                elt = n.toElement();
                couleur = elt.text();
            }
            n = n.nextSibling();
        }
        return poly;
    }
    else
    {
        return NULL;
    }
}
