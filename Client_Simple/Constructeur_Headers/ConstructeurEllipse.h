#ifndef CONSTRUCTEURELLIPSE_H
#define CONSTRUCTEURELLIPSE_H

#include "ConstructeurCOR.h"
#include "../Headers/Ellipse.h"

class ConstructeurEllipse : public ConstructeurCOR
{
public:
    ConstructeurEllipse(ConstructeurCOR *);
    Figure * resoudre1(const QDomNode*) const;
};

#endif // CONSTRUCTEURELLIPSE_H
