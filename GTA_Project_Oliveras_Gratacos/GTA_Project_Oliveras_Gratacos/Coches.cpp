#include "Coches.h"
#include "mapa.h"

Coches::Coches()
{	
	plInCar = false;
	bool aux = false;
	while (!aux)
	{
		Position.X = (rand() % (leftLimit1 - 2)) + 1;
		Position.Y = (rand() % (Height - 2)) + 1;

		if (mapa.getCella(Position.X, Position.Y) == Cella::VACIA)
		{
			aux = true;
		}
	}
}



Coches::~Coches()
{

}