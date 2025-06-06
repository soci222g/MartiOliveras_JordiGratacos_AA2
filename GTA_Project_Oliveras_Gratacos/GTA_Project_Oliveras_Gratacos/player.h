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
class Coches;
class Player
{
public:
	Player();
	~Player();

	void Reed_input(Actions input);

	Actions getMoveInput() const { return moveInput; }
	Vector getVector()const { return position; }
	Vector getVectorCar()const { return posCoche; }
	Actions getLastMoveInput() const { return lastMoveInput; }
	void SeeIfCanMove(Mapa mapa, bool& GameOver);
	void setPlVector(Vector v) { position.X = v.X;  position.Y = v.Y; }
	void setInCarTrue() { inCar = true; }
	void setFcanEnterCar() { canEnterCar = false; }

	void stopNPC(peaton& peaton);
	void stopBS(BigSmoke& BS);

	void AtackPeaton(peaton& peatones, Mapa mapa);
	void AtackBigSmoke(BigSmoke& BG, Mapa mapa);
	bool GetCanMove() const { return canMove; }
	bool GetcanEnterCar() const { return canEnterCar; }
	bool GetInCar() const { return inCar; }

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
	Vector posCoche;
	Vector position;
	Actions moveInput;
	Actions lastMoveInput;
	int Damage;
	int CurrentIsland;
	int vista;
};

