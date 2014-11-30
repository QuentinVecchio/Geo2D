#ifndef CONSTRUCTEURCARRE_H
#define CONSTRUCTEURCARRE_H

#include "ConstructeurCOR.h"
#include "../Headers/Carre.h"

class ConstructeurCarre : public ConstructeurCOR
{
public:
    ConstructeurCarre(ConstructeurCOR *);
    Figure * resoudre1(const QDomNode*) const;
};

#endif // CONSTRUCTEURCARRE_H
