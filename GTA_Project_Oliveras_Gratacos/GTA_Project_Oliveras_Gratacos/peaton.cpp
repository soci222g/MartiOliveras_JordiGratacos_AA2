#include "peaton.h"
#include "mapa.h"
#include"lecturaArchivo.h"


peaton::peaton(int leftLimit1, int left_limit2,int Height, int mapaNum, int id)
{
	LecturaArchivo archivo;
	Frames = 60;
	AtackColldown = 0;
	
	Alive = true;
	ID = id;
	CanMove = true;
	NumIsla = mapaNum;
	//int tempSelect = rand() % 2;
	int tempSelect = 0;
	if (tempSelect == 0) {
		Agresive = true;
	}
	else if (tempSelect == 1) {
		Agresive = false;
	}


	if (NumIsla == 1) {
		
		Position.X = (rand() % (leftLimit1 - 2)) + 1;
		Position.Y = (rand() % (Height - 2)) + 1;
		powerPeaton = archivo.GetpowerPeatones1();
		HP = archivo.GethpPeatones1();
		
	}
	if (NumIsla == 2) {
		Position.X = (rand() % (leftLimit1 - 2)) + (leftLimit1 + 2);
		Position.Y = (rand() % (Height - 2)) + 1;
		powerPeaton = archivo.GetpowerPeatones2();
		HP = archivo.GethpPeatones2();
	}
	if (NumIsla == 3) {
		Position.X = (rand() % (leftLimit1 - 1)) + (left_limit2 + 1); // 27 + 12 
		Position.Y = (rand() % (Height - 2)) + 1;
		powerPeaton = archivo.GetpowerPeatones3();
		HP = archivo.GethpPeatones3();
	}
	MaxHP = HP;

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
	LecturaArchivo archivo;

	Alive = true;
	ID = id;
	CanMove = true;

	if (NumIsla == 1) {

		Position.X = (rand() % (leftLimit1 - 2)) + 1;
		Position.Y = (rand() % (Height - 2)) + 1;
		HP = archivo.GethpPeatones1();
	}
	if (NumIsla == 2) {
		Position.X = (rand() % (leftLimit1 - 2)) + (leftLimit1 + 2);
		Position.Y = (rand() % (Height - 2)) + 1;
		HP = archivo.GethpPeatones2();
	}
	if (NumIsla == 3) {
		Position.X = (rand() % (leftLimit1 - 1)) + (left_limit2 + 1); // 27 + 12 
		Position.Y = (rand() % (Height - 2)) + 1;
		HP = archivo.GethpPeatones3();
	}

	if (mapa.getCella(Position.X, Position.Y) != Cella::VACIA) {
		RespawnPeaton(leftLimit1, left_limit2,  Height,id,mapa);
	}
	
}


void peaton::atackPlayer(Player& jugador) {
	jugador.SetHP(powerPeaton);
}

void peaton::DamagePeaton(int damage) {
	HP -= damage;
	AtackColldown = Frames;
}

void peaton::SeeIFDead() {
	if (HP <= 0) {
		Alive = false;
	}
}



void peaton::LifeCoin(Mapa& mapa) {
	mapa.SetCella(Position.X, Position.Y, Cella::DINERO);
}