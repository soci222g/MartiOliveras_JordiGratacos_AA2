#include "peaton.h"
#include "mapa.h"


peaton::peaton()
{

}

peaton::peaton(int leftLimit1, int left_limit2,int Height, int mapaNum, int id)
{

	ID = id;
	CanMove = true;

	if (mapaNum == 1) {
		
		Position.X = (rand() % (leftLimit1 - 2)) + 1;
		Position.Y = (rand() % (Height - 2)) + 1;
	}
	if (mapaNum == 2) {
		Position.X = (rand() % (leftLimit1 - 2)) + (leftLimit1 + 2);
		Position.Y = (rand() % (Height - 2)) + 1;
	}
	

}

peaton::~peaton() {

}

void peaton::NewRandomPosition(Mapa& mapa) {
	
	int moveThisFrame = rand() % 1;
	int newNumPosition = (rand() % 4) + 1 ;

	int X = Position.X;
	int Y = Position.Y;

	if (newNumPosition == 1) {
		if (mapa.getCella(X + 1, Y) == Cella::VACIA) {
			Position.X++;
		}
	}
	if (newNumPosition == 2) {
		if (mapa.getCella(X - 1, Y) == Cella::VACIA) {
			Position.X--;
		}
	}
	if (newNumPosition == 3) {
		if (mapa.getCella(X, Y + 1) == Cella::VACIA) {
			Position.Y++;
		}

	}
	if (newNumPosition == 4) {
		if (mapa.getCella(X,Y - 1) == Cella::VACIA) {
			Position.Y--;
		}
	}

	
}