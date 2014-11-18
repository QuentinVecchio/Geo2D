#ifndef EXCEPTIONGEO2D_H
#define EXCEPTIONGEO2D_H
#include <string>
#include <iostream>
using namespace std;

class ExceptionGeo2D{
private:
    string message;
public:
    ExceptionGeo2D(const string& m);
    string get_erreur()const;
    ~ExceptionGeo2D(){}
};

#endif // EXCEPTIONGEO2D_H
