#include"player.h"
#include"mapa.h"
#include"lecturaArchivo.h"
Player::Player()
{
	LecturaArchivo archivo;

	hp = archivo.GetHpCJ();
	position.X = 4;
	position.Y = 2;
	mony = 0;
	moveInput = Actions::UP;
	lastMoveInput = Actions::UP;
	CurrentIsland = 1;
	Damage = archivo.GetPowerCJ();
	canMove = true;
	vista = 5;
}



Player::~Player() {

}

void Player::stopNPC(peaton& peaton) {
	for (int i = position.Y - 1; i < position.Y + 1; i++) {
		for (int j = position.X - 1; j < position.X + 1; j++) {
			if (peaton.GetPosition().Y == i && peaton.GetPosition().X == j) {
				peaton.SetCanMove(false);
				return;
			}
		}
	}
	peaton.SetCanMove(true);
}

void Player::SeeIfCanMove(Mapa mapa, bool& GameOver) {
	int X = position.X;
	int Y = position.Y;
	if (moveInput == Actions::UP) {
		if (mapa.getCella(X, Y - 1) == Cella::VACIA ) {
			canMove = true;
			
		}
		else if (mapa.getCella(X, Y - 1) == Cella::PEAJE) {
			GameOver = true;
		}
		else if (mapa.getCella(X, Y - 1) == Cella::DINERO) {
			if (CurrentIsland == 1) {
				addDinero(mapa.GetMaxDineroIsla1());
			}
			else if(CurrentIsland == 2){
				addDinero(mapa.GetMaxDineroIsla2());
			}
			canMove = true;
		}
		else {
			canMove = false;
		}
	}
	if (moveInput == Actions::DOWN) {
		if (mapa.getCella(X, Y + 1) == Cella::VACIA || mapa.getCella(X, Y + 1) == Cella::PEATON) {
			canMove = true;
			
		}
		else if (mapa.getCella(X, Y + 1) == Cella::PEAJE) {
			GameOver = true;
		}
		else if (mapa.getCella(X, Y + 1) == Cella::DINERO) {
			if (CurrentIsland == 1) {
				addDinero(mapa.GetMaxDineroIsla1());
			}
			else if (CurrentIsland == 2) {
				addDinero(mapa.GetMaxDineroIsla2());
			}
			canMove = true;
		}
		else {
			canMove = false;
		}
	}
	if (moveInput == Actions::RIGHT) {
		if (mapa.getCella(X + 1, Y) == Cella::VACIA || mapa.getCella(X + 1, Y) == Cella::PEATON) {
			canMove = true;
			
		}
		else if (mapa.getCella(X + 1, Y) == Cella::PEAJE) {
			GameOver = true;
		}
		else if (mapa.getCella(X + 1, Y) == Cella::DINERO) {
			if (CurrentIsland == 1) {
				addDinero(mapa.GetMaxDineroIsla1());
			}
			else if (CurrentIsland == 2) {
				addDinero(mapa.GetMaxDineroIsla2());
			}
			canMove = true;
		}
		else {
			canMove = false;
		}
	}
	if (moveInput == Actions::LEFT) {
		if (mapa.getCella(X - 1,Y) == Cella::VACIA || mapa.getCella(X - 1, Y) == Cella::PEATON) {
			canMove = true;
			
		}
		else if (mapa.getCella(X - 1, Y) == Cella::PEAJE) {
			GameOver = true;
		}
		else if (mapa.getCella(X - 1, Y) == Cella::DINERO) {
			if (CurrentIsland == 1) {
				addDinero(mapa.GetMaxDineroIsla1());
			}
			else if (CurrentIsland == 2) {
				addDinero(mapa.GetMaxDineroIsla2());
			}
			canMove = true;
		}
		else {
			canMove = false;
		}
	}

}

void Player::addDinero(int maxDienro) {

	int monyGet = rand() % maxDienro + 1;

	mony += monyGet;

}

void Player::Reed_input(Actions input) {
	if (input == Actions::UP) {
		position.Y--;
		lastMoveInput = Actions::UP;
	}

	if (input == Actions::DOWN) {
		position.Y++;
		lastMoveInput = Actions::DOWN;
	}
	if (input == Actions::LEFT) {
		position.X--;
		lastMoveInput = Actions::LEFT;
	}
	if (input == Actions::RIGHT) {
		position.X++;
		lastMoveInput = Actions::RIGHT;
	}

}

void Player::AtackPeaton(peaton& peatones, Mapa mapa) {
	int X = position.X;
	int Y = position.Y;
	if (peatones.getCanMove() == false) {
		peatones.DamagePeaton(Damage);
	}
}


void Player::EnterCar(Mapa mapa) {

}