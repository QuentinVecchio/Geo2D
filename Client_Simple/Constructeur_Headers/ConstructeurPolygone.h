#ifndef CONSTRUCTEURPOLYGONE_H
#define CONSTRUCTEURPOLYGONE_H

#include "ConstructeurCOR.h"
#include "../Headers/Polygone.h"

class ConstructeurPolygone : public ConstructeurCOR
{
public:
    ConstructeurPolygone(ConstructeurCOR *);
    Figure * resoudre1(const QDomNode*) const;
};

#endif // CONSTRUCTEURPOLYGONE_H
