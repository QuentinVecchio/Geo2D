#ifndef OBJETCONTROLLER_H
#define OBJETCONTROLLER_H

class ObjetController
{
private:
    ObjetController();
public:
    ~ObjetController();

    virtual QLayout * getView() const = 0;
    virtual void construction() = 0;
};

#endif // OBJETCONTROLLER_H
