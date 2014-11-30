#ifndef COULEUR_H
#define COULEUR_H

#include <QString>

using namespace std;
class Couleur
{
private:
    static const QString strCouleur[];
public:
    static QString getCouleur(const int i);
    enum Couleurs { BLACK, BLUE, RED, GREEN, YELLOW, CYAN, NB__ };
    static Couleurs getNameCouleur(const QString);
};
#endif
