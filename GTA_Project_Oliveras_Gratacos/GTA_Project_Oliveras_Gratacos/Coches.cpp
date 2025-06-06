#include "Coches.h"
#include"lecturaArchivo.h"

Coches::Coches()
{
	LecturaArchivo archivo;
	nCarI1 = archivo.GetnCoche1();
	nCarI2 = archivo.GetnCoche2();
	nCarI3 = archivo.GetnCoche3();


}



Coches::~Coches()
{

}