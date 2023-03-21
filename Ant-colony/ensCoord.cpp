#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <time.h>

#include "coord.hpp"
#include "ensCoord.hpp"

using namespace std;

Coord randomEC (EnsCoord e){
	int v = rand() % e.sizeUsed;
	if(e.sizeUsed == 0){
		cout<<"L'ensemble est vide - ERREUR"<<endl;
		Coord ce;
		ce.x = -1;
		ce.y = -1;
		return ce;
	}
	return e.t[v];
}

void creeEnsVide (EnsCoord &e) {
	e.sizeUsed = 0;
}


int chercheCoordEns(EnsCoord e, Coord c){
	for(int i = 0; i<tailleGrille*tailleGrille; i++){
		if(e.t[i].x == c.x and e.t[i].y == c.y){
			return i;
		}
	}
	cout<<"La coordonnée n'a pas été trouvée dans le tableau"<<endl;
	return -1;
}

void retirerCoord(EnsCoord &e, Coord c){
	int indice = chercheCoordEns(e, c);
	for(int i = indice; i<e.sizeUsed - 1; i++){
		e.t[i] = e.t[i+1];
	} 
	e.sizeUsed--;
}

void afficheEnsCoord(EnsCoord e) {
	for(int i = 0; i<e.sizeUsed; i++){
		e.t[i].afficheCoord();
		cout<<"   -   ";
	}
	cout<<endl;
}

EnsCoord trouverVoisins (Coord c) {
	EnsCoord e;
	creeEnsVide(e);
	if(c.x < tailleGrille-1){
		ajouterCoord(e, creeCoord(c.x + 1, c.y));
		if(c.y < tailleGrille-1){
			ajouterCoord(e, creeCoord(c.x + 1, c.y + 1));
		}
		if(c.y > 0){
			ajouterCoord(e, creeCoord(c.x + 1, c.y - 1));
		}
	}
	if(c.x > 0){
		ajouterCoord(e, creeCoord(c.x - 1, c.y));
		if(c.y < tailleGrille-1){
			ajouterCoord(e, creeCoord(c.x - 1, c.y + 1));
		}
		if(c.y > 0){
			ajouterCoord(e, creeCoord(c.x - 1, c.y - 1));
		}
	}
	if(c.y > 0){
		ajouterCoord(e, creeCoord(c.x, c.y -1));
	}
	if(c.y < tailleGrille-1){
		ajouterCoord(e, creeCoord(c.x, c.y + 1));
	}
	return e;
}

void ajouterCoord(EnsCoord &e, Coord c) {
	if(e.sizeUsed == tailleGrille*tailleGrille){
		cout<<"erreur - le tableau de EnsCoord est plein"<<endl;
		afficheEnsCoord(e);
		cout<<"____"<<endl;
		return;
	}
	e.t[e.sizeUsed] = c;
	e.sizeUsed++;
}

int cardEC(EnsCoord e){
	return e.sizeUsed;
}
