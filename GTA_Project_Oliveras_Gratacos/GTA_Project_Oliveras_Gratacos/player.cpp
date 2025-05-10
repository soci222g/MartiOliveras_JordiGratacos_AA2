#include"player.h"


Player::Player()
{
	hp = 100;
	position.X = 2;
	position.Y = 2;
	mony = 0;
	moveInput = Movement::UP;

}

Player::~Player()
{
}

void Player::Reed_input(std::string input) {
	if (input == "W" || input == "w") {
		moveInput = Movement::UP;
	}

	if (input == "S" || input == "s") {
		moveInput = Movement::DOWM;
	}
	if (input == "A" || input == "a") {
		moveInput = Movement::LEFT;
	}
	if (input == "D" || input == "d") {
		moveInput = Movement::RIGHT;
	}

}

void Player::Move_Player(std::string input) {
	if (input == "W" || input == "w") {
		position.Y--;
	}

	if (input == "S" || input == "s") {
		position.Y++;
	}
	if (input == "A" || input == "a") {
		position.X--;
	}
	if (input == "D" || input == "d") {
		position.X++;
	}


}