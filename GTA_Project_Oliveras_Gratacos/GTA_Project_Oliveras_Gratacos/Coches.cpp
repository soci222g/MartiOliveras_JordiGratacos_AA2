#include "Coches.h"
#include"lecturaArchivo.h"

Coches::Coches()
{
	LecturaArchivo archivo;
	const nCarI1 = archivo.GetnCoche1();
	const nCarI2 = archivo.GetnCoche2();
	const nCarI3 = archivo.GetnCoche3();

	Coche cocheI1[nCarI1];
	Coche cocheI2[nCarI2];
	Coche cocheI3[nCarI3];

	for (int i = 0; i < nCarI1; i++) {
		cocheI1[i].Position.X = (rand() % (leftLimit1 - 2)) + 1;
		cocheI1[i].Position.Y = (rand() % (Height - 2)) + 1;
	}
	for (int i = 0; i < nCarI2; i++) {
		cocheI2[i].Position.X = (rand() % (leftLimit1 - 2)) + 1;
		cocheI2[i].Position.Y = (rand() % (Height - 2)) + 1;
	}
	for (int i = 0; i < nCarI3; i++) {
		cocheI3[i].Position.X = (rand() % (leftLimit1 - 2)) + 1;
		cocheI3[i].Position.Y = (rand() % (Height - 2)) + 1;
	}
}



Coches::~Coches()
{

}