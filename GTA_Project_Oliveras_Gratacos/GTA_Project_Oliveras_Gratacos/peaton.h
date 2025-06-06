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
	bool getCanMove() const { return CanMove; }
	bool getAlive() const { return alive; }

	
	

	int getID() const { return ID; }
	void setAlive(bool notDead) { alive = notDead; }

	void NewRandomPosition(Mapa& map);
	void SeeIFDead();
	void DamagePeaton(int damage);
	void LifeCoin(Mapa& mapa);

	Vector GetPosition() const { return Position; }

private:

	Vector Position;
	bool CanMove;
	int ID;
	bool alive;
	int HP;
};


