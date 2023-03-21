#include <iostream>
#include <vector>

#include "place.hpp"
#include "coord.hpp"
#include "fourmis.hpp"

using namespace std;


Place creerPlace(Coord c){
	Place p;
	p.c = c;
	p.pheroSucre = 0;
	p.pheroNid = 0.;
	p.numeroFourmi = -1;
	p.sucre = false;
	return p;
}

bool Place::contientSucre(){
	return sucre;
}

bool Place::contientNid(){
	if(pheroNid == 1) { return true; }
	return false;
}

bool Place::estSurUnePiste(){
	if(pheroSucre > 0) { return true; }
	return false;
}

bool Place::contientFourmi(){
	if(numeroFourmi == -1) { return false; }
	return true;
}

bool Place::estVide(){
	if(!contientNid() && !contientFourmi() && !contientSucre()) { return true; }
	return false;
}

void Place::poseSucre(){
	if(sucre) { cout<<"Attention il y a déjà du sucre sur cette case - dépot impossible"<<endl; }
	sucre = true;
}

void Place::enleveSucre(){
	if(!sucre) { cout<<"Attention il n'y a pas de sucre sur cette case - retrait impossible"<<endl; }
	sucre = false;
}

void Place::poseNid(){
	pheroNid = 1;
}

void Place::poseFourmi(Fourmi f){
	numeroFourmi = f.num;
}

void Place::enleveFourmi(){
	numeroFourmi = -1;
}

void Place::posePheroNid(float f){
	pheroNid = f;
}

void Place::posePheroSucre(){
	pheroSucre = 255;
}

void Place::diminuePheroSucre(){
	if(pheroSucre - redPheroSucre <= 0) { pheroSucre = 0; return; }
	pheroSucre = pheroSucre - redPheroSucre;
}
