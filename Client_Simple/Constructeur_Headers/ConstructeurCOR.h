#ifndef CONSTRUCTEURCOR_H
#define CONSTRUCTEURCOR_H

#include "constructeur.h"

class ConstructeurCOR : public Constructeur
{
private:
    ConstructeurCOR * suivant;
protected:
    ConstructeurCOR(ConstructeurCOR *);
public:
    Figure* resoudre (const QDomNode*) const;
protected:
    virtual Figure * resoudre1(const QDomNode*) const = 0;
};

#endif // CONSTRUCTEURCOR_H
