#ifndef CONSTRUCTEURSEGMENT_H
#define CONSTRUCTEURSEGMENT_H

#include "ConstructeurCOR.h"
#include "../Headers/Segment.h"

class ConstructeurSegment : public ConstructeurCOR
{
public:
    ConstructeurSegment(ConstructeurCOR *);
    Figure * resoudre1(const QDomNode*) const;
};

#endif // CONSTRUCTEURSEGMENT_H
