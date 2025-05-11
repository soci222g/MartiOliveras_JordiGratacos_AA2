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