#ifndef CONSTRUCTEURCERCLE_H
#define CONSTRUCTEURCERCLE_H

#include "ConstructeurCOR.h"
#include "../Headers/Cercle.h"

class ConstructeurCercle : public ConstructeurCOR
{
public:
    ConstructeurCercle(ConstructeurCOR *);
    Figure * resoudre1(const QDomNode*) const;
};
#endif // CONSTRUCTEURCERCLE_H
