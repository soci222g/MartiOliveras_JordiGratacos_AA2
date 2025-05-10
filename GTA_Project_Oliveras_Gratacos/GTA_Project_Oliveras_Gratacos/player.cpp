#include"player.h"


Player::Player()
{
	hp = 100;
	position.X = 2;
	position.Y = 2;
	mony = 0;
}

Player::~Player()
{
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