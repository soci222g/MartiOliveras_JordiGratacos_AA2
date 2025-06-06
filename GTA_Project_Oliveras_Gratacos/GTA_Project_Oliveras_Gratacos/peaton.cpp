#include "peaton.h"
#include "mapa.h"


peaton::peaton()
{

}

peaton::peaton(int leftLimit1, int left_limit2,int Height, int mapaNum, int id)
{
	HP = 1;
	alive = true;
	ID = id;
	CanMove = true;
	NumIsla = mapaNum;

	if (NumIsla == 1) {
		
		Position.X = (rand() % (leftLimit1 - 2)) + 1;
		Position.Y = (rand() % (Height - 2)) + 1;
	}
	if (NumIsla == 2) {
		Position.X = (rand() % (leftLimit1 - 2)) + (leftLimit1 + 2);
		Position.Y = (rand() % (Height - 2)) + 1;
	}
	if (NumIsla == 3) {
		Position.X = (rand() % (leftLimit1 - 1)) + (left_limit2 + 1); // 27 + 12 
		Position.Y = (rand() % (Height - 2)) + 1;
	}
	

}

peaton::~peaton() {

}



void peaton::NewRandomPosition(Mapa& mapa) {
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


void peaton::RespawnPeaton(int leftLimit1, int left_limit2, int Height,int id, Mapa mapa) {
	HP = 1;
	alive = true;
	ID = id;
	CanMove = true;

	if (NumIsla == 1) {

		Position.X = (rand() % (leftLimit1 - 2)) + 1;
		Position.Y = (rand() % (Height - 2)) + 1;
	}
	if (NumIsla == 2) {
		Position.X = (rand() % (leftLimit1 - 2)) + (leftLimit1 + 2);
		Position.Y = (rand() % (Height - 2)) + 1;
	}
	if (NumIsla == 3) {
		Position.X = (rand() % (leftLimit1 - 1)) + (left_limit2 + 1); // 27 + 12 
		Position.Y = (rand() % (Height - 2)) + 1;
	}

	if (mapa.getCella(Position.X, Position.Y) != Cella::VACIA) {
		RespawnPeaton(leftLimit1, left_limit2,  Height,id,mapa);
	}
	
}

void peaton::DamagePeaton(int damage) {
	HP -= damage;
}

void peaton::SeeIFDead() {
	if (HP <= 0) {
		alive = false;
	}
}



void peaton::LifeCoin(Mapa& mapa) {
	mapa.SetCella(Position.X, Position.Y, Cella::DINERO);
}