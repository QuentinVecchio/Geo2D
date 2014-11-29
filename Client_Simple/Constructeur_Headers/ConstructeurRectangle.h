#ifndef CONSTRUCTEURRECTANGLE_H
#define CONSTRUCTEURRECTANGLE_H

#include "ConstructeurCOR.h"
#include "../Headers/Rectangle.h"

class ConstructeurRectangle : public ConstructeurCOR
{
public:
    ConstructeurRectangle(ConstructeurCOR *);
    Figure * resoudre1(const QDomNode*) const;
};

#endif // CONSTRUCTEURRECTANGLE_H
