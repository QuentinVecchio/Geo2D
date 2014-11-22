#ifndef CONSTRUCTEUR_H
#define CONSTRUCTEUR_H

#include "../Headers/Figure.h"
#include <QtXml>

class Constructeur
{
public:
    virtual Figure* resoudre(const QDomNode*) const = 0;
};

#endif // CONSTRUCTEUR_H
