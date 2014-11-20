#ifndef POINTCONTROLLER_H
#define POINTCONTROLLER_H

#include "objetcontroller.h"
#include "QLayout"
#include "pointview.h"
#include "point.h"

class PointController : ObjetController
{
private:
    //Point *p;
    PointView *v;
public:
    PointController();
    ~PointController();

    QLayout * getView() const;
    void construction();
};

#endif // POINTCONTROLLER_H
