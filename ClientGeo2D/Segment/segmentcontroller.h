#ifndef SEGMENTCONTROLLER_H
#define SEGMENTCONTROLLER_H

#include "objetcontroller.h"
#include "QLayout"
#include "segmentview.h"
#include "segment.h"

class SegmentController : ObjetController
{
private:
    Segment *s;
    SegmentView *v;
public:
    SegmentController();
    ~SegmentController();

    QLayout * getView() const;
    void construction();
};

#endif // SEGMENTCONTROLLER_H
