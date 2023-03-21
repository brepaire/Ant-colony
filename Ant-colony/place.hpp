#ifndef PLACE
#define PLACE

#include "coord.hpp"
#include "fourmis.hpp"

const int redPheroSucre = 5;

struct Place {
	Coord c;
	int pheroSucre;
	float pheroNid;
	int numeroFourmi;
	bool sucre;
	
	bool contientSucre();
	bool contientNid();
	bool estSurUnePiste();
	bool contientFourmi();
	bool estVide();
	
	void poseSucre();
	void enleveSucre();
	void poseNid();
	void poseFourmi(Fourmi f);
	void enleveFourmi();
	void posePheroNid(float f);
	void posePheroSucre();
	void diminuePheroSucre();
};

Place creerPlace(Coord c);

#endif

