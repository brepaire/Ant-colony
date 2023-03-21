#ifndef FOURMI
#define FOURMI

#include "coord.hpp"

struct Fourmi {
	Coord coord;
	int num;
	bool sucre;
	bool vivante;
	
	bool chercheSucre();
	bool rentreNid();
	bool estVivante();	
	
	void prendSucre();
	void poseSucre();
	void deplace(Coord c);
};

Fourmi creerFourmi (Coord c, int num);
void afficheFourmi(Fourmi f);

#endif

