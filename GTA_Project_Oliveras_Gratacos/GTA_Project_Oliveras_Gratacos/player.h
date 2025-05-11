#pragma once
#include"Vector.h"
#include<iostream>

enum class Movement
{
	UP,
	DOWM,
	LEFT,
	RIGHT,
	COUNT
};

class Player
{
public:
	Player();
	~Player();

	void Reed_input(std::string input);

	Movement getMoveInput() { return moveInput; }
	Vector getVector() { return position; }

	int GetVista() { return vista; }

	void Move_Player(std::string input);

private:
	int hp;
	int mony;
	Vector position;
	Movement moveInput;
	

	int vista;
};

