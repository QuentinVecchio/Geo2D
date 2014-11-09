#ifndef FORMULAIRE_H
#define FORMULAIRE_H

#include "QLabel"
#include "QLineEdit"
#include "QString"
#include "QLayout"
#include "QComboBox"
#include "QHBoxLayout"
#include "QVBoxLayout"

class Formulaire
{
private:
    QLabel *label;
    QLineEdit *x1;
    QLineEdit *y1;
    QComboBox *couleurs;
    QHBoxLayout *layoutPrincipal;
protected:
    Formulaire(const QString s);
    QVBoxLayout *layoutSecondaire;
public:
    virtual ~Formulaire();

    QString getLabel() const;
    float getX1() const;
    float getY1() const;
    QLayout* getView() const;

    void setLabel(const QString s);
    void setX1(const float f);
    void setY1(const float f);
};

#endif // FORMULAIRE_H
