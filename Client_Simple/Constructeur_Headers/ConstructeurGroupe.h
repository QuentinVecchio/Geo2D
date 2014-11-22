#ifndef CONSTRUCTEURGROUPE_H
#define CONSTRUCTEURGROUPE_H

#include "ConstructeurCOR.h"
#include "../Headers/Groupe.h"

class ConstructeurGroupe : public ConstructeurCOR
{
public:
    ConstructeurGroupe(ConstructeurCOR *);
    Figure * resoudre1(const QDomNode*) const;
};

#endif // CONSTRUCTEURGROUPE_H
