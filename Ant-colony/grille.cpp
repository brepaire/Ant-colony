#include <iostream>
#include <vector>
#include <iomanip> // pour setfill, setw
#include <sstream> // pour ostringstream
#include <fstream> // pour ofstream
#include <string>

#include "grille.hpp"
#include "coord.hpp"
#include "place.hpp"
#include "fourmis.hpp"
#include "ensCoord.hpp"

using namespace std;

Grille creerGrille(){
	Grille g;
	for(int i = 0; i<tailleGrille; i++){
		for(int j = 0; j<tailleGrille; j++){
			g.tab[i][j] = creerPlace(creeCoord (i, j));
		}
	}
	g.vF = vector<Fourmi>();
	return g;
}

Place Grille::chargePlace(Coord c){
	Place p = tab[c.getX()][c.getY()];
	return p;
}

void Grille::rangePlace(Place p){
	Coord co = p.c;
	int x = co.getX();
	int y = co.getY();
	tab[x][y] = p;
}
	
void Grille::linearisePheroNid(){
	for(int i = 0; i<tailleGrille; i++){
		for(int j = 0; j<tailleGrille; j++){
			//TODO
		}
	}
}

void Grille::diminuePheroSucre(){
	for(int i = 0; i<tailleGrille; i++){
		for(int j = 0; j<tailleGrille; j++){
			tab[i][j].diminuePheroSucre();
		}
	}
}

void Grille::initialiseGrille(){
	vector<Fourmi> vf;
	
	//INITIALISE LE NID
	int milieu = (int) tailleGrille/2;
	Coord c1 = creeCoord(milieu, milieu);
	Coord c2 = creeCoord(milieu+1, milieu);
	Coord c3 = creeCoord(milieu, milieu+1);
	Coord c4 = creeCoord(milieu+1, milieu+1);
	Place p1 = chargePlace(c1);
	p1.poseNid();
	rangePlace(p1);
	Place p2 = chargePlace(c2);
	p2.poseNid();
	rangePlace(p2);
	Place p3 = chargePlace(c3);
	p3.poseNid();
	rangePlace(p3);
	Place p4 = chargePlace(c4);
	p4.poseNid();
	rangePlace(p4);
	
	//INITIALISE LES FOURMIS
	Coord c5 = creeCoord(milieu-1, milieu-1);
	Fourmi f1 = creerFourmi(c5, 0);
	Coord c6 = creeCoord(milieu-1, milieu);
	Fourmi f2 = creerFourmi(c6, 1);
	Coord c7 = creeCoord(milieu-1, milieu+1);
	Fourmi f3 = creerFourmi(c7, 2);
	Coord c8 = creeCoord(milieu-1, milieu+2);
	Fourmi f4 = creerFourmi(c8, 3);
	Coord c9 = creeCoord(milieu, milieu-1);
	Fourmi f5 = creerFourmi(c9, 4);
	Coord c10 = creeCoord(milieu, milieu+2);
	Fourmi f6 = creerFourmi(c10, 5);
	Coord c11 = creeCoord(milieu+1, milieu-1);
	Fourmi f7 = creerFourmi(c11, 6);
	Coord c12 = creeCoord(milieu+1, milieu+2);
	Fourmi f8 = creerFourmi(c12, 7);
	Coord c13 = creeCoord(milieu+2, milieu-1);
	Fourmi f9 = creerFourmi(c13, 8);
	Coord c14 = creeCoord(milieu+2, milieu);
	Fourmi f10 = creerFourmi(c14, 9);
	Coord c15 = creeCoord(milieu+2, milieu+1);
	Fourmi f11 = creerFourmi(c15, 10);
	Coord c16 = creeCoord(milieu+2, milieu+2);
	Fourmi f12 = creerFourmi(c16, 11);
	
	vf.push_back(f1);
	vf.push_back(f2);
	vf.push_back(f3);
	vf.push_back(f4);
	vf.push_back(f5);
	vf.push_back(f6);
	vf.push_back(f7);
	vf.push_back(f8);
	vf.push_back(f9);
	vf.push_back(f10);
	vf.push_back(f11);
	vf.push_back(f12);
	
	Place p5 = chargePlace(c5);
	p5.poseFourmi(f1);
	rangePlace(p5);
	Place p6 = chargePlace(c6);
	p6.poseFourmi(f2);
	rangePlace(p6);
	Place p7 = chargePlace(c7);
	p7.poseFourmi(f3);
	rangePlace(p7);
	Place p8 = chargePlace(c8);
	p8.poseFourmi(f4);
	rangePlace(p8);
	Place p9 = chargePlace(c9);
	p9.poseFourmi(f5);
	rangePlace(p9);
	Place p10 = chargePlace(c10);
	p10.poseFourmi(f6);
	rangePlace(p10);
	Place p11 = chargePlace(c11);
	p11.poseFourmi(f7);
	rangePlace(p11);
	Place p12 = chargePlace(c12);
	p12.poseFourmi(f8);
	rangePlace(p12);
	Place p13 = chargePlace(c13);
	p13.poseFourmi(f9);
	rangePlace(p13);
	Place p14 = chargePlace(c14);
	p14.poseFourmi(f10);
	rangePlace(p14);
	Place p15 = chargePlace(c15);
	p15.poseFourmi(f11);
	rangePlace(p15);
	Place p16 = chargePlace(c16);
	p16.poseFourmi(f12);
	rangePlace(p16);
	
	//INITIALISE LE SUCRE
	Place p17 = chargePlace(creeCoord(tailleGrille-2, 0));
	p17.poseSucre();
	rangePlace(p17);
	Place p18 = chargePlace(creeCoord(2, tailleGrille-1));
	p18.poseSucre();
	rangePlace(p18);
	vF = vf;
	
	linearisePheroNid();
}

void Grille::afficheGrille(){
	cout<<endl;
	for(int i = 0; i<tailleGrille; i++){
		for(int j = 0; j<tailleGrille; j++){		
			Place p = tab[i][j];
			if(p.numeroFourmi != -1){ cout<<" F "; }
			else if (p.contientSucre()) { cout<<" S "; }
			else if (p.contientNid()) { cout<<" N "; }
		  else { cout <<"   "; }
		}
		cout<<endl;
	}
	cout<<endl;
}

void Grille::dessineGrille(int compteurFichier){
	int r,g,b;
	ostringstream filename;
	// creation d’un nouveau nom de fichier de la forme img347.ppm
	filename << "img" << setfill('0') << setw(3) << compteurFichier << ".ppm";
	cout << "Ecriture dans le fichier : " << filename.str() << endl;
	// ouverture du fichier
	ofstream fic(filename.str(), ios::out | ios::trunc);
	// ecriture de l’entete
	fic << "P3" << endl
	<< tailleGrille << " " << tailleGrille << " " << endl
	<< 255 << " " << endl;
	// ecriture des pixels
	for (int i = 0; i < tailleGrille; i++){
		for (int j = 0; j < tailleGrille; j++){
			// calcul de la couleur
			if(tab[i][j].contientFourmi()){
				r = 255; g = 255; b = 0;
			} else if(tab[i][j].contientSucre()){
				 r = 255; g = 255; b = 255;
			} else if(tab[i][j].contientNid()){
				r = 0; g = 0; b = 255;
			} else {
				r = 0; g = tab[i][j].pheroSucre; b = 0;
			}
		// ecriture de la couleur dans le fichier
		fic << r << " " << g << " " << b << " ";
		}
		// fin de ligne dans l’image
		fic << endl;
	}
	// fermeture du fichier
	fic.close();
}

void Grille::deplacerFourmi(Fourmi f, Place p1, Place p2){
	Coord dep = p1.c;
	Coord arr = p2.c;
	if(f.coord.getX() != dep.getX() && f.coord.getY() != dep.getY()) { cout<<"Erreur dans la fonction de deplacement de la fourmi !!!"<<endl; return; }

	Place depP = chargePlace(dep);
	Place arrP = chargePlace(arr);

	int num = f.num;

	f.deplace(arr);
	vF[num] = f;
	
	depP.enleveFourmi();
	arrP.poseFourmi(f);
	
	rangePlace(depP);
	rangePlace(arrP);
}

void Grille::updateFourmi(){
	int n = vF.size();
	for(int i = 0; i<n; i++){
		bool action = false;
		for(int k = 1; k<= 7; k++){
			EnsCoord voisinF = trouverVoisins(vF[i].coord);
			int size = cardEC(voisinF);
			//pour chaque règle on test pour les cases voisines
			for(int j = 0; j<size; j++){
				Coord c = randomEC(voisinF);
				Place p = chargePlace(c);
				retirerCoord(voisinF, c);
				//if(condition1(vF[i], p) && (k==1) && (action==false)){ cout<<"ici1"<<endl; action1(vF[i], p); action=true; return; }
				if(condition2(vF[i], p) && (k==2) && (action==false)){ action2(vF[i], p); action=true; }
				if(condition3(vF[i], p) && (k==3) && (action==false)){ action3(vF[i], p); action=true; }
				if(condition4(vF[i], p) && (k==4) && (action==false)){ action4(vF[i], p); action=true; }
				if(condition5(vF[i], p) && (k==5) && (action==false)){ action5(vF[i], p); action=true; }
				if(condition6(vF[i], p) && (k==6) && (action==false)){ action6(vF[i], p); action=true; }
				if(condition7(vF[i], p) && (k==7) && (action==false)){ action7(vF[i], p); action=true; }
			}
		}
	}
}	


EnsCoord Grille::ensFourmi(){
	EnsCoord e;
	creeEnsVide(e);
	for(int i = 0; i<tailleGrille; i++){
		for(int j = 0; j<tailleGrille; j++){
			Place p = tab[i][j];
			if(p.contientFourmi()){
				Coord c = creeCoord(i,j);
				ajouterCoord(e, c);
			}
		}
	}
	return e;
}

EnsCoord Grille::ensNid(){
	EnsCoord e;
	creeEnsVide(e);
	for(int i = 0; i<tailleGrille; i++){
		for(int j = 0; j<tailleGrille; j++){
			Place p = tab[i][j];
			if(p.contientNid()){
				Coord c = creeCoord(i,j);
				ajouterCoord(e, c);
			}
		}
	}
	return e;
}	

bool Grille::plusProcheNid(Place p1, Place p2){
	EnsCoord en = ensNid();
	int sump1 = 0;
	int sump2 = 0;
	for(int i = 0; i<cardEC(en); i++){
		sump1 = sump1 + distance(p1.c, en.t[i]);
		sump2 = sump2 + distance(p2.c, en.t[i]);
	}
	if(sump1<=sump2){ return true; }
	return false;
}


//CONDITIONS POUR LE DEPLACEMENT

bool Grille::condition1(Fourmi f, Place p2){
	Place p = tab[p2.c.getX()][p2.c.getY()];
	return f.estVivante() && p.contientFourmi();
}

bool Grille::condition2(Fourmi f, Place p2){
	Place p = tab[p2.c.getX()][p2.c.getY()];
	return f.chercheSucre() && p.contientSucre();
}	

bool Grille::condition3(Fourmi f, Place p2){
	Place p = tab[p2.c.getX()][p2.c.getY()];
	return f.rentreNid() && p.contientNid();
}

bool Grille::condition4(Fourmi f, Place p2){
	Place p = tab[p2.c.getX()][p2.c.getY()];
	Place p1 = chargePlace(f.coord);
	return f.rentreNid() && p.estVide() && plusProcheNid(p, p1);
}

bool Grille::condition5(Fourmi f, Place p2){
	Place p = tab[p2.c.getX()][p2.c.getY()];
	Place pf = tab[f.coord.getX()][f.coord.getY()];
	return f.chercheSucre() && p.estSurUnePiste() && pf.estSurUnePiste() && p.estVide() && plusProcheNid(pf,p);
}

bool Grille::condition6(Fourmi f, Place p2){
	Place p = tab[p2.c.getX()][p2.c.getY()];
	return f.chercheSucre() && p.estSurUnePiste() && p.estVide();
}

bool Grille::condition7(Fourmi f, Place p2){
	Place p = tab[p2.c.getX()][p2.c.getY()];
	return f.chercheSucre() && p.estVide();
}

void Grille::action1(Fourmi f, Place p2){
	//TODO ici on a implémenté une seule colonie donc rien à faire
}

void Grille::action2(Fourmi f, Place p2){
	//cout<<"action 2"<<endl;
	int num = f.num;
	f.prendSucre();
	Place p = chargePlace(f.coord);
	p.posePheroSucre();
	rangePlace(p);
	vF[num] = f;
	
}

void Grille::action3(Fourmi f, Place p2){
	//cout<<"action 3"<<endl;
	int num = f.num;
	f.poseSucre();
	vF[num] = f;
}

void Grille::action4(Fourmi f, Place p2){
	//cout<<"action 4"<<endl;
	Place p = chargePlace(p2.c);
	p.posePheroSucre();
	rangePlace(p);
	Place p1 = chargePlace(f.coord);
	deplacerFourmi(f, p1, p2);
}

void Grille::action5(Fourmi f, Place p2){
	//cout<<"action 5"<<endl;
	Place p = chargePlace(p2.c);
	Place p1 = chargePlace(f.coord);
	deplacerFourmi(f, p1, p);
}

void Grille::action6(Fourmi f, Place p2){
	//cout<<"action 6"<<endl;
	Place p = chargePlace(p2.c);
	Place p1 = chargePlace(f.coord);
	deplacerFourmi(f, p1, p);
}

void Grille::action7(Fourmi f, Place p2){
	//cout<<"action 7"<<endl;
	Place p = chargePlace(p2.c);
	Place p1 = chargePlace(f.coord);
	deplacerFourmi(f, p1, p);
}

void Grille::apparitionSucre(){
	EnsCoord e;
	creeEnsVide(e);
	for(int i = 0; i<tailleGrille; i++){
		for(int j = 0; j<tailleGrille; j++){
			Place p = tab[i][j];
			if(p.estVide()){
				Coord c = creeCoord(i,j);
				ajouterCoord(e, c);
			}
		}
	}
	Coord c1 = randomEC(e);
	Place p = chargePlace(c1);
	p.poseSucre();
	rangePlace(p);	
}
