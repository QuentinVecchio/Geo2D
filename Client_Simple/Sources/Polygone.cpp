#include "Headers/Polygone.h"
#include <algorithm>

Polygone::Polygone(const Point p1, const Point p2, const Couleur c, const vector<Segment*> polygone):Segment(p1,p2,c){
	this->v = polygone;
}

/*Getters & Setters*/
Segment Polygone::getSegment(const int i)const{
	if (i < 0 || i >= nbElements()){
		abort();
	}
	else{
		return *v[i];
	}
}

int Polygone::nbElements()const{
	return this->v.size();
}


/*Fonctions*/
void Polygone::translation(const Point p){
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
	void operator () (Segment* s){
		flux << *s << endl;
	}

};

ostream& operator <<(ostream& flux, const Polygone& p){
	AffObjet aff(flux);
	for_each(p.v.begin(), p.v.end(), AffObjet(flux));
	return flux;
}

