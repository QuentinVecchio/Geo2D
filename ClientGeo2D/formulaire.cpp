#include "formulaire.h"

Formulaire::Formulaire(const QString s)
{
    this->couleurs = new QComboBox();
    this->couleurs->addItem("Noir");
    this->couleurs->addItem("Bleu");
    this->label = new QLabel(s);
    this->layoutPrincipal = new QHBoxLayout();
    this->layoutPrincipal->addWidget(this->label);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(new QLabel("X1 :"));
    layout->addWidget(this->x1);
    layout->addWidget(new QLabel("Y1 :"));
    layout->addWidget(this->y1);
    this->layoutSecondaire = new QVBoxLayout();
    this->layoutSecondaire->addWidget(layout);
    this->layoutSecondaire->addWidget(this->couleurs);
    this->layoutPrincipal->addWidget(this->layoutSecondaire);
}

Formulaire::~Formulaire()
{
    delete this->label;
    delete this->x1;
    delete this->y1;
}

QLayout* Formulaire::getView() const
{
    return this->layoutPrincipal;
}

QString Formulaire::getLabel() const
{
    return this->label->text();
}

float Formulaire::getX1() const
{

}

float Formulaire::getY1() const
{

}

void Formulaire::setLabel(const QString s)
{
    this->label->setText(s);
}

void Formulaire::setX1(const float f)
{

}

void Formulaire::setY1(const float f)
{

}
