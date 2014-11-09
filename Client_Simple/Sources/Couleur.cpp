#include "Headers/Couleur.h"

const string Couleur::strCouleur[] = { "BLACK", "BLUE", "RED", "GREEN", "YELLOW", "CYAN" };

string Couleur::getCouleur(const int i){
	if (i < 0 || i > NB__){
		abort();
	}
	return strCouleur[i];
}

