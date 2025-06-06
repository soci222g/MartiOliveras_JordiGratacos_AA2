#pragma once
#include"Vector.h"
#include "mapa.h"



class mapa;
class BigSmoke
{
public:
	BigSmoke(int leftLimit1, int left_limit2, int Height);
	~BigSmoke();
	

	void SetCanMove(bool newState) { CanMove = newState; }
	bool getCanMove() const { return CanMove; }
	bool getAlive() const { return Alive; }
	void ResetColldown() { AtackColldown = Frames; }

	



	void setAlive(bool notDead) { Alive = notDead; }

	void NewRandomPosition(Mapa& map);
	void SeeIFDead();
	void DamageBigSmoke(int damage);
	
	void atackPlayer(Player& jugador);
	void subStracColldown() { AtackColldown--; }

	Vector GetPosition() const { return Position; }
	int GetColldownAtack() const { return AtackColldown; }
	int GetMaxHP() const { return MaxHP; }
	int GetHP() const { return HP; }
private:

	Vector Position;
	bool CanMove;
	
	bool Alive;
	int HP;
	int MaxHP;
	int PowerBigSmoke;
	int AtackColldown;
	int Frames;

};


