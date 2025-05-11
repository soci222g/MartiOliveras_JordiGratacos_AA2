#include"player.h"


Player::Player()
{
	hp = 100;
	position.X = 4;
	position.Y = 2;
	mony = 0;
	moveInput = Actions::UP;
	lastMoveInput = Actions::UP;


	vista = 5;
}

Player::~Player() {

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