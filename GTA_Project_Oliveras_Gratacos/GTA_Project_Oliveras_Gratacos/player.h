#pragma once
#include"Vector.h"
#include"peaton.h"
#include"BigSmoke.h"
#include<iostream>


enum class Actions
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE,
	COUNT,
};
class Mapa;
class peaton;
class BigSmoke;
class Player
{
public:
	Player();
	~Player();

	void Reed_input(Actions input);

	Actions getMoveInput() const { return moveInput; }
	Vector getVector()const { return position; }
	Actions getLastMoveInput() const { return lastMoveInput; }
	void SeeIfCanMove(Mapa mapa, bool& GameOver);

	void stopNPC(peaton& peaton);
	void stopBS(BigSmoke& BS);

	void AtackPeaton(peaton& peatones, Mapa mapa);
	void AtackBigSmoke(BigSmoke& BG, Mapa mapa);
	bool GetCanMove() const { return canMove; }

	int GetVista() const { return vista; }

	int GetHP() const { return hp; }
	int GetMony() const { return mony; }

	void SetHP(int Damage) { hp -= Damage; }

	void setMoveInput(Actions action) { moveInput = action; }

	void EnterCar(Coches coche);
	void restDinero(int DineroResta) {mony = mony - DineroResta;}

	void addDinero(int maxDinero);

private:
	int hp;
	int mony;
	bool canMove;
	bool canEnterCar;
	bool inCar;
	Vector position;
	Actions moveInput;
	Actions lastMoveInput;
	int Damage;
	int CurrentIsland;
	int vista;
};

