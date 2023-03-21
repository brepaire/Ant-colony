#include <iostream>
#include <vector>

#include "coord.hpp"
#include "fourmis.hpp"
#include "grille.hpp"
#include "place.hpp"
#include "ensCoord.hpp"


using namespace std;

void simulation(){
	Grille g;
	g = creerGrille();
	g.initialiseGrille();
	g.afficheGrille();
	
	for(int i = 0; i<300; i++){
		/*int next = -1;
		cout<<"taper un entier positif pour continuer"<<endl;
		while(next < 0){
			cin>>next;
		}*/
		g.updateFourmi();
		g.diminuePheroSucre();
		if(i%20 == 0 && i != 0){
			g.apparitionSucre();
		}	
		//g.afficheGrille();
		g.dessineGrille(i);
	}

}

int main(){
 /*Grille g;
	g = creerGrille();
	g.initialiseGrille();
	g.afficheGrille();
	cout<<"***"<<endl;
	int milieu = (int) tailleGrille/2;
	Place p1 = g.tab[milieu-1][milieu-1];
	Place p2 = g.tab[milieu-1][milieu-2];
	Fourmi f = creerFourmi(p1.c, p1.numeroFourmi);
	g.deplacerFourmi(f, p1, p2);
	g.afficheGrille();
	cout<<endl;
	for(int j = 0; j<30; j++){
		EnsCoord e = g.ensFourmi();
		//afficheEnsCoord(e);
		for(int i = 0; i<cardEC(e); i++){
			EnsCoord eF = trouverVoisins(e.t[i]);
			Place p1F = g.chargePlace(e.t[i]);
			Coord r = randomEC(eF);
			Place r1 = g.chargePlace(r);
			while(!r1.estVide()){
				r = randomEC(eF);
				r1 = g.chargePlace(r);			
			}

			g.deplacerFourmi(g.vF[p1F.numeroFourmi], p1F, r1);

			//cout<<"Deplacement n° "<<i<<endl;
			//g.afficheGrille();
		}
	}
	g.afficheGrille();*/

	cout<<"Début de la simulation"<<endl;
	simulation();
	cout<<"Fin de la simulation"<<endl;
}
