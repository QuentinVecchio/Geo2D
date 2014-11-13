#include "Headers/Couleur.h"

const QString Couleur::strCouleur[] = { "BLACK", "BLUE", "RED", "GREEN", "YELLOW", "CYAN" };

QString Couleur::getCouleur(const int i)
{
    if (i < 0 || i > NB__)
    {
		abort();
	}
	return strCouleur[i];
}

