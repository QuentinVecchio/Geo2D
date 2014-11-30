#include "../Headers/ExceptionGeo2D.h"


ExceptionGeo2D::ExceptionGeo2D(const string& m)
{
    this->message = m;
}

string ExceptionGeo2D::get_erreur()const{
    return this->message;
}
