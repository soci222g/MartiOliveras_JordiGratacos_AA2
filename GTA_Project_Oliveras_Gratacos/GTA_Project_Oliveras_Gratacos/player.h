#pragma once
#include"Vector.h"
#include<iostream>

enum class Actions
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE,
	COUNT,
};

class Player
{
public:
	Player();
	~Player();

	void Reed_input(Actions input);

	Actions getMoveInput() { return moveInput; }
	Vector getVector() { return position; }
	Actions getLastMoveInput() { return lastMoveInput; }


	int GetVista() { return vista; }

	void setMoveInput(Actions action) { moveInput = action; }

private:
	int hp;
	int mony;
	Vector position;
	Actions moveInput;
	Actions lastMoveInput;
	

	int vista;
};

