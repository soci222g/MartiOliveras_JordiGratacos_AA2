#pragma once
#include "Vector.h"

class Mapa;
class Coches
{
private:
	Vector posCar;
	bool plInCar;
public:
	Coches();
	~Coches();
	Vector GetPositionCar() const { return posCar; }
	bool GetplInCar() const { return plInCar; }
};

