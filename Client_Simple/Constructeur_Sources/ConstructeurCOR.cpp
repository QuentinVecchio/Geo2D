#include "../Constructeur_Headers/ConstructeurCOR.h"

ConstructeurCOR::ConstructeurCOR(ConstructeurCOR *s)
{
    this->suivant = s;
}

Figure* ConstructeurCOR::resoudre (const QDomNode* d) const
{
    Figure * f = this->resoudre1(d);
    if(f != NULL)
        return f;
    else
        if(this->suivant != NULL)
            return this->suivant->resoudre(d);
        else
            return NULL;
}
