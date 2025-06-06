#pragma once
#include "Vector.h"

class Mapa;
class Coches
{
private:
	Vector Position;
	bool plInCar;
public:
	Coches(int leftLimit1, int left_limit2, int height, int mapaNum, Mapa mapa);
	~Coches();
	Vector GetPositionCar() const { return Position; }
	bool GetplInCar() const { return plInCar; }
};

