#include "Coches.h"
#include "mapa.h"

Coches::Coches(int leftLimit1, int left_limit2, int height, int mapaNum, Mapa mapa)
{	
	plInCar = false;
	bool aux = false;
	Position.X = 1;
	Position.Y = 1;
	while (!aux)
	{

		if (mapaNum == 1) {

			Position.X = (rand() % (leftLimit1 - 2)) + 1;
			Position.Y = (rand() % (height - 2)) + 1;
		}
		if (mapaNum == 2) {
			Position.X = (rand() % (leftLimit1 - 2)) + (leftLimit1 + 2);
			Position.Y = (rand() % (height - 2)) + 1;
		}
		if (mapaNum == 3) {
			Position.X = (rand() % (leftLimit1 - 1)) + (left_limit2 + 1); // 27 + 12 
			Position.Y = (rand() % (height - 2)) + 1;
		}


		if (mapa.getCella(Position.X, Position.Y) == Cella::VACIA)
		{
			aux = true;
		}
	}
}



Coches::~Coches()
{

}