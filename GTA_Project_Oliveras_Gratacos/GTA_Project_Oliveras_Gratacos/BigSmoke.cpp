#include"BigSmoke.h"

BigSmoke::BigSmoke(int leftLimit1, int left_limit2, int Height)
{
	
	Frames = 10; //cada segundo
	AtackColldown = 0;

	Alive = true;
	
	CanMove = true;
	
	
	Position.X = (rand() % (leftLimit1 - 1)) + (left_limit2 + 1); // 27 + 12 	
	Position.Y = (rand() % (Height - 2)) + 1;
	
	PowerBigSmoke = 40;
	HP = 150;
	
	MaxHP = HP;

}




void BigSmoke::NewRandomPosition(Mapa& mapa) {
	if (CanMove == true) {
		int moveThisFrame = rand() % 1;
		int newNumPosition = (rand() % 4) + 1;

		int X = Position.X;
		int Y = Position.Y;

		if (newNumPosition == 1) {
			if (mapa.getCella(X + 1, Y) == Cella::VACIA) {
				Position.X++;
			}
		}
		if (newNumPosition == 2) {
			if (mapa.getCella(X - 1, Y) == Cella::VACIA) {
				Position.X--;
			}
		}
		if (newNumPosition == 3) {
			if (mapa.getCella(X, Y + 1) == Cella::VACIA) {
				Position.Y++;
			}

		}
		if (newNumPosition == 4) {
			if (mapa.getCella(X, Y - 1) == Cella::VACIA) {
				Position.Y--;
			}
		}

	}
}





void BigSmoke::atackPlayer(Player& jugador) {
	jugador.SetHP(PowerBigSmoke);
	AtackColldown = Frames;
}

void BigSmoke::DamageBigSmoke(int damage) {
	HP -= damage;
}

void BigSmoke::SeeIFDead() {
	if (HP <= 0) {
		Alive = false;
	}
}





BigSmoke::~BigSmoke()
{
}