#include "Headers/Groupe.h"
#include <algorithm>

Groupe::Groupe(const Point p1, const Couleur c, const vector<Figure*> polygone):Figure(p1,c){
	this->v = polygone;
}

/*Getters & Setters*/
Figure Groupe::getFigure(const int i)const{
	if (i < 0 || i >= nbElements()){
		abort();
	}
	else{
		return *v[i];
	}
}
int Groupe::nbElements()const{
	return this->v.size();
}

/*Fonctions*/
void Groupe::translation(const Point p){
	for (int i = 0; i < v.size(); i++)
	{
		this->v[i]->translation(p);
	}
}
//void rotation();
//void homothetie();

// foncteur pour afficher
class AffObjet{
private:
	ostream& flux;
public:
	AffObjet(ostream& flux) :flux(flux){};
	void operator () (Figure* f){
		flux << *f << endl;
	}

};

ostream& operator <<(ostream& flux, const Groupe& g){
	AffObjet aff(flux);
	for_each(g.v.begin(), g.v.end(), AffObjet(flux));
	return flux;
}

