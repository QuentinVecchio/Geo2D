#include "segmentcontroller.h"

SegmentController::SegmentController()
{
    this->s = new Segment(new Point(0,0), new Point(0,0));
    this->v = new SegmentView("Segment :");
}

SegmentController::~SegmentController()
{
    delete this->s;
    delete this->v;
}

QLayout* SegmentController::getView() const
{
    this->v->getView();
}

void SegmentController::construction()
{
    this->p->setX(this->v->getX1());
    this->p->setY(this->v->getY1());
}
