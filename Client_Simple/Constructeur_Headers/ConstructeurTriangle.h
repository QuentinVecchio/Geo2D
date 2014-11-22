#ifndef CONSTRUCTEURTRIANGLE_H
#define CONSTRUCTEURTRIANGLE_H

#include "ConstructeurCOR.h"
#include "../Headers/Triangle.h"

class ConstructeurTriangle : public ConstructeurCOR
{
public:
    ConstructeurTriangle(ConstructeurCOR *);
    Figure * resoudre1(const QDomNode*) const;
};

#endif // CONSTRUCTEURTRIANGLE_H
