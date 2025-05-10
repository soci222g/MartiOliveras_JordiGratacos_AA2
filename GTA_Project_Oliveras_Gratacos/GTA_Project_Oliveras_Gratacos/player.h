#pragma once
#include"Vector.h"
#include<iostream>
class Player
{
public:
	Player();
	~Player();

	void Move_Player(std::string input);

private:
	int hp;
	int mony;
	Vector position;
	


	int vista;
};

