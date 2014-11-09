#include "pointcontroller.h"

PointController::PointController()
{
    this->v = new PointView("Point :");
}

PointController::~PointController()
{
    //delete this->point;
    delete this->v;
}

QLayout* PointController::getView() const
{
    this->v->getView();
}

void PointController::construction()
{
    //this->p = new Point(this->v->getX1(),this->v->getY1());
}
