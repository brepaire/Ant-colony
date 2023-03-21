#ifndef ENSCOORD
#define ENSCOORD

#include "coord.hpp"

const int tailleGrille = 20;

using tab = Coord[tailleGrille*tailleGrille];

struct EnsCoord {
	tab t;
	int sizeUsed;
};

Coord randomEC (EnsCoord e);

void creeEnsVide (EnsCoord &e);

void ajouterCoord(EnsCoord &e, Coord c);

int chercheCoordEns(EnsCoord e, Coord c);

void retirerCoord(EnsCoord &e, Coord c);

void afficheEnsCoord(EnsCoord e);

EnsCoord trouverVoisins (Coord c); 

int cardEC(EnsCoord e);

#endif
