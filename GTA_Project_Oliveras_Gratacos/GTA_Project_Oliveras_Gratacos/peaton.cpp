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
	int newNumPosition = (rand() % 4) + 1 ;


	switch (newNumPosition)
	{
	case 1:
		if (mapa.getCella(Position.X += 1,Position.Y) == Cella::VACIA) {
			Position.X += 1;
		}
		break;
	case 2:
		if (mapa.getCella(Position.X -= 1, Position.Y) == Cella::VACIA) {
			Position.X -= 1;
		}
		break;
	case 3:
		if (mapa.getCella(Position.X , Position.Y += 1) == Cella::VACIA) {
			Position.Y += 1;
		}
		
		break;
	case 4:
		if (mapa.getCella(Position.X, Position.Y -= 1) == Cella::VACIA) {
			Position.Y -= 1;
		}
		break;

	}
}