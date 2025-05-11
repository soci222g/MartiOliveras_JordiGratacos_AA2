
#include <fstream>
#include <iostream>
#include<Windows.h>


#include"mapa.h"
#include"player.h"
#include"peaton.h"



int main()
{
	srand(time(NULL));
	
	Player player;
	Mapa mapa;
	
	std::vector<peaton> SavePeatones;
	// +1 per el id
	for (int i = 1; i < mapa.GetN_peatones1() + 1; i++) {
		peaton peatons(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight(), 1, i);
		SavePeatones.push_back(peatons);
	}
	for (int i = 1; i < mapa.GetN_peatones2() + 1; i++) {
		peaton peatons(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight(), 2, i);
		SavePeatones.push_back(peatons);
	}
	
	mapa.addPlayerMapa(player);
	int pasAddMapa = 0;
	
	for (int i = 0; i < SavePeatones.size(); i++) {
		mapa.addPeatoneMapa(SavePeatones[i]);
		pasAddMapa++;
	}

	bool gameOver = false;
	while (!gameOver)
	{
		//INPUTS
		if (GetAsyncKeyState(VK_UP))
		{
			player.setMoveInput(Actions::UP);
			mapa.generateEmpty(player.getVector());
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
			player.setMoveInput(Actions::LEFT);
			mapa.generateEmpty(player.getVector());

		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			player.setMoveInput(Actions::DOWN);
			mapa.generateEmpty(player.getVector());

		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			player.setMoveInput(Actions::RIGHT);
			mapa.generateEmpty(player.getVector());

		}
		else if (GetAsyncKeyState(VK_SPACE))
		{
			//player.robPeaton();
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			gameOver = true;
		}
		else
		{
			player.setMoveInput(Actions::NONE);
		}

		//UPDATE
		player.SeeIfCanMove(mapa);
		
		if (player.GetCanMove() == true) {
			player.Reed_input(player.getMoveInput());
		}
		
		mapa.addPlayerMapa(player);
		mapa.printPlayerView(player);
		//mapa.printMapaTotal(player);


		Sleep(500);
		system("CLS");
	}
}
