#include"player.h"
#include"mapa.h"
Player::Player()
{
	hp = 100;
	position.X = 4;
	position.Y = 2;
	mony = 0;
	moveInput = Actions::UP;
	lastMoveInput = Actions::UP;

	canMove = true;
	vista = 5;
}



Player::~Player() {

}

void Player::stopNPC(peaton peaton) {
	for (int i = position.Y - 1; i < position.Y + 1; i++) {
		for (int j = position.X - 1; j < position.X + 1; j++) {
			if (peaton.GetPosition().Y == j && peaton.GetPosition().X == i) {
				peaton.SetCanMove(false);
				
			}
			else {
				peaton.SetCanMove(true);
			}

		}
	}
}

void Player::SeeIfCanMove(Mapa mapa) {
	int X = position.X;
	int Y = position.Y;
	if (moveInput == Actions::UP) {
		if (mapa.getCella(X, Y - 1) == Cella::VACIA || mapa.getCella(X, Y - 1) == Cella::PEATON) {
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
		else {
			canMove = false;
		}
	}
	if (moveInput == Actions::RIGHT) {
		if (mapa.getCella(X + 1, Y) == Cella::VACIA || mapa.getCella(X + 1, Y) == Cella::PEATON) {
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
		else {
			canMove = false;
		}
	}

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

void Player::AtackPeaton(peaton peatones, Mapa mapa) {
	int X = position.X;
	int Y = position.Y;

	if (lastMoveInput == Actions::UP)
	{
		if (mapa.getCella(X, Y - 1) == Cella::PEATON && peatones.GetPosition().X == X && peatones.GetPosition().Y == Y - 1) {
				bool notDead = false;
				peatones.setAlive(notDead);
				mapa.SetCella(X, Y - 1, Cella::DINERO);
		}
			
	}
	if (lastMoveInput == Actions::DOWN)
	{
		if (mapa.getCella(X, Y + 1) == Cella::PEATON && peatones.GetPosition().X == X && peatones.GetPosition().Y == Y + 1) {
			bool notDead = false;
			peatones.setAlive(notDead);
			mapa.SetCella(X, Y + 1, Cella::DINERO);
		}
	}
	if (lastMoveInput == Actions::RIGHT)
	{
		if (mapa.getCella(X + 1, Y ) == Cella::PEATON && peatones.GetPosition().X == X + 1 && peatones.GetPosition().Y == Y ) {
			bool notDead = false;
			peatones.setAlive(notDead);
			mapa.SetCella(X + 1, Y, Cella::DINERO);
		}
	}
	if (lastMoveInput == Actions::LEFT)
	{
		if (mapa.getCella(X - 1, Y) == Cella::PEATON && peatones.GetPosition().X == X - 1 && peatones.GetPosition().Y == Y ) {
			bool notDead = false;
			peatones.setAlive(notDead);
			mapa.SetCella(X - 1, Y, Cella::DINERO);
		}
	}
}