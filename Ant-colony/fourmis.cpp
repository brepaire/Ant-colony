#include <iostream>
#include <vector>

#include "fourmis.hpp"
#include "coord.hpp"

using namespace std;


Fourmi creerFourmi (Coord c, int num) {
	Fourmi f;
	f.coord = c;
	f.num = num;
	f.sucre = false;
	f.vivante = true;
	return f;
}

bool Fourmi::chercheSucre(){
	if(sucre) { return false; }
	return true;
}

bool Fourmi::rentreNid(){
	if(sucre) { return true; }
	return false;
}

bool Fourmi::estVivante(){
	if(vivante) { return true; }
	return false;
}

void Fourmi::prendSucre(){
	if(sucre) { cout<<"Attention la fourmi porte déjà du sucre"<<endl; }
	sucre = true;
}

void Fourmi::poseSucre(){
	if(!sucre) { cout<<"Attention la fourmi n'a pas de sucre de déposer"<<endl; }
	sucre = false;
}

void Fourmi::deplace(Coord c){
	coord = c;
}

void afficheFourmi(Fourmi f){
	cout<<"La fourmi n°"<<f.num<<" à la case ";
	f.coord.afficheCoord();
	if(f.sucre){
		cout<<" porte du sucre"<<endl;
	} else {
		cout<<" ne porte pas de sucre"<<endl;
	}
}
