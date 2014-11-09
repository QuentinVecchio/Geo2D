#ifndef COULEUR_H
#define COULEUR_H

#include <string>
using namespace std;
class Couleur
{
private:
	static const string strCouleur[];
	// strCouleur[NOIR] ==> "NOIR"
public:
	static string getCouleur(const int i);
	enum Couleurs { BLACK, BLUE, RED, GREEN, YELLOW, CYAN, NB__ };
};
#endif
