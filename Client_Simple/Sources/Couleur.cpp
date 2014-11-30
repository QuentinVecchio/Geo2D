#include "../Headers/Couleur.h"

const QString Couleur::strCouleur[] = { "BLACK", "BLUE", "RED", "GREEN", "YELLOW", "CYAN" };

QString Couleur::getCouleur(const int i)
{
    if (i < 0 || i > NB__)
    {
		abort();
	}
	return strCouleur[i];
}

Couleur::Couleurs Couleur::getNameCouleur(const QString s)
{
    if(s == "BLACK")
        return Couleur::BLACK;
    else if(s == "BLUE")
        return Couleur::BLUE;
    else if(s == "RED")
        return Couleur::RED;
    else if(s == "GREEN")
        return Couleur::GREEN;
    else if(s == "BLUE")
        return Couleur::BLUE;
    else if(s == "YELLOW")
        return Couleur::YELLOW;
    else if(s == "CYAN")
        return Couleur::CYAN;
    else
        return Couleur::BLACK;
}
