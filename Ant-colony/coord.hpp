#ifndef COORD
#define COORD

struct Coord {
	int x,y;
	
	int getX();
	int getY();
	
	void afficheCoord();
};

Coord creeCoord (int x, int y);
float distance(Coord c1, Coord c2);
#endif
