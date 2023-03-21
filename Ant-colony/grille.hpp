#ifndef GRILLE
#define GRILLE

#include <vector>

#include "coord.hpp"
#include "place.hpp"
#include "fourmis.hpp"
#include "ensCoord.hpp"

struct Grille{
	Place tab[tailleGrille][tailleGrille];
	std::vector<Fourmi> vF;
	
	Place chargePlace(Coord c);
	void rangePlace(Place p);
	
	void linearisePheroNid();
	void diminuePheroSucre();
	
	//Un exemple d'initialisation
	void initialiseGrille();
	
	void afficheGrille();
	void dessineGrille(int compteurFichier);
	void deplacerFourmi(Fourmi f, Place p1, Place p2);
	void updateFourmi();
	
	EnsCoord ensFourmi();
	EnsCoord ensNid();
	
	bool plusProcheNid(Place p1, Place p2);
	void apparitionSucre();
	
	
	bool condition1(Fourmi f, Place p2);
	bool condition2(Fourmi f, Place p2);
	bool condition3(Fourmi f, Place p2);
	bool condition4(Fourmi f, Place p2);
	bool condition5(Fourmi f, Place p2);
	bool condition6(Fourmi f, Place p2);
	bool condition7(Fourmi f, Place p2);

	void action1(Fourmi f, Place p2);
	void action2(Fourmi f, Place p2);
	void action3(Fourmi f, Place p2);
	void action4(Fourmi f, Place p2);
	void action5(Fourmi f, Place p2);
	void action6(Fourmi f, Place p2);
	void action7(Fourmi f, Place p2);

};


Grille creerGrille();



#endif
