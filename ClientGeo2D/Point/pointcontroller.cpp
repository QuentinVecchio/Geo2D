#include "pointcontroller.h"

PointController::PointController()
{
    this->p = new Point(0,0);
    this->v = new PointView("Point :");
}

PointController::~PointController()
{
    delete this->p;
    delete this->v;
}

QLayout* PointController::getView() const
{
    this->v->getView();
}

void PointController::construction()
{
    this->p->setX(this->v->getX1());
    this->p->setY(this->v->getY1());
}
