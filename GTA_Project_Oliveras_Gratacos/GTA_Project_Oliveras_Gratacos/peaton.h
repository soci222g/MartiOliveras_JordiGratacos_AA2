#pragma once
#include "Vector.h"
#include"Player.h"
#include <fstream>
class Mapa;
class Player;
class peaton
{
public:
	peaton(int leftLimit1, int left_limit2,int Height, int mapaNum,int id);
	~peaton();

	void SetCanMove(bool newState) { CanMove = newState; }
	bool getCanMove() const { return CanMove; }
	bool getAlive() const { return Alive; }

	
	void RespawnPeaton(int leftLimit1, int left_limit2, int Height, int id, Mapa mapa);


	int getID() const { return ID; }
	void setAlive(bool notDead) { Alive = notDead; }

	void NewRandomPosition(Mapa& map);
	void SeeIFDead();
	void DamagePeaton(int damage);
	void LifeCoin(Mapa& mapa);
	void atackPlayer(Player& jugador);
	void subStracColldown() { AtackColldown--; }
	void ResetColldown() { AtackColldown = Frames; }

	Vector GetPosition() const { return Position; }
	int GetColldownAtack() const { return AtackColldown; }
	int GetMaxHP() const {return MaxHP;	}
	int GetHP() const { return HP; }
	bool GetAgresive() const { return Agresive; }
private:

	Vector Position;
	bool CanMove;
	int ID;
	bool Alive;
	int HP;
	int MaxHP;
	int NumIsla;
	int powerPeaton;
	bool Agresive;
	int AtackColldown;
	int Frames;

};


