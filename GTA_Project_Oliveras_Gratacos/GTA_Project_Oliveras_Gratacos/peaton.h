#pragma once
#include "Vector.h"

#include <fstream>
class Mapa;
class peaton
{
public:
	peaton();
	peaton(int leftLimit1, int left_limit2, int Height, int mapaNum,int id);
	~peaton();

	void SetCanMove(bool newState) { CanMove = newState; }
	bool getCanMove() { return CanMove; }

	void NewRandomPosition(Mapa& map);
	Vector GetPosition() { return Position; }

private:

	Vector Position;
	bool CanMove;
	int ID;
};


