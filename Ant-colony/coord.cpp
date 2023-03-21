#include <iostream>
#include <vector>
#include <cmath>

#include "coord.hpp"

using namespace std;


Coord creeCoord (int x, int y) {
	Coord c;
	c.x = x;
	c.y = y;
	return c;
}

int Coord::getX () {
	return x;
}

int Coord::getY () {
	return y;
}

void Coord::afficheCoord() {
	cout<<"("<<x<<", "<<y<<")";
}

float distance(Coord c1, Coord c2){
	return sqrt(pow(c2.getX()-c1.getX(),2)+pow(c2.getY()-c1.getY(),2)*1.0);
}
