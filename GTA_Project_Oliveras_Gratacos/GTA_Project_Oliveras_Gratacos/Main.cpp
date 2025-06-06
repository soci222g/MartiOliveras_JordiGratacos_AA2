
#include <fstream>
#include <iostream>
#include<Windows.h>


#include"mapa.h"
#include"player.h"
#include"peaton.h"
#include"Coches.h"
#include"BigSmoke.h"


int main()
{
	srand(time(NULL));
	
	Player player;
	Mapa mapa;
	BigSmoke BS(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight());


	const int NUM_FPS = 60;

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
	for (int i = 1; i < mapa.GetN_peatones3() + 1; i++) {
		peaton peatons(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight(), 3, i);
		SavePeatones.push_back(peatons);
	}

	

	std::vector<Coches> cotxes;

	for (int i = 1; i < mapa.GetNCarI1() + 1; i++) {
		Coches coche(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight(), 1, mapa);
		cotxes.push_back(coche);
	}
	for (int i = 1; i < mapa.GetNCarI2() + 1; i++) {
		Coches coche(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight(), 2, mapa);
		cotxes.push_back(coche);
	}
	for (int i = 1; i < mapa.GetNCarI3() + 1; i++) {
		Coches coche(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight(), 3, mapa);
		cotxes.push_back(coche);
	}


	for (int i = 0; i < cotxes.size(); i++) {
		mapa.addCocheMapa(cotxes[i]);
	}

	mapa.addPlayerMapa(player);
	mapa.addBigSmokeMapa(BS);
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
			for (int i = 0; i < SavePeatones.size(); i++) {
				player.AtackPeaton(SavePeatones[i], mapa);
				SavePeatones[i].SeeIFDead();
 				if (SavePeatones[i].getAlive() == false) {
					mapa.GenerateCoin(SavePeatones[i].GetPosition());
					SavePeatones[i].RespawnPeaton(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight(),i, mapa);
				}
			}
			player.AtackBigSmoke(BS, mapa);
			BS.SeeIFDead();
			if (BS.getAlive() == false) {
				gameOver = true;
			}


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
		player.SeeIfCanMove(mapa, gameOver);
		
		if (player.GetCanMove() == true) {
			player.Reed_input(player.getMoveInput());
		}
		
	

		for (int i = 0; i < SavePeatones.size(); i++) {
			player.stopNPC(SavePeatones[i]);
			if (SavePeatones[i].getCanMove()) {
				mapa.generateEmpty(SavePeatones[i].GetPosition());
				SavePeatones[i].NewRandomPosition(mapa);
				mapa.addPeatoneMapa(SavePeatones[i]);
			}
			else { //en caso de que no se puedan mover
				if (SavePeatones[i].GetAgresive()) { // codigo de si el npc es agresivo
					if (SavePeatones[i].GetHP() < SavePeatones[i].GetMaxHP()) {
						if (SavePeatones[i].GetColldownAtack() <= 0) {
							SavePeatones[i].atackPlayer(player);
							SavePeatones[i].ResetColldown();
						}
						else {
							SavePeatones[i].subStracColldown();
						}
					}
				} //no hace nada en caso contrario

			}

		}
		//big smoke logic
		player.stopBS(BS);
		if (BS.getCanMove()) {
			mapa.generateEmpty(BS.GetPosition());
			BS.NewRandomPosition(mapa);
			mapa.addBigSmokeMapa(BS);
		}
		else { //en caso de que no se puedan mover
			if (BS.GetHP() < BS.GetMaxHP()) {
					if (BS.GetColldownAtack() <= 0) {
						BS.atackPlayer(player);
						BS.ResetColldown();
					}
					else {
						BS.subStracColldown();
					}
				
			} //no hace nada en caso contrario

		}

		



		mapa.addPlayerMapa(player);
		
		mapa.PayPeaje(player);


		
		
		//mapa.printPlayerView(player);
		

		
		mapa.printMapaTotal(player);

		if (player.GetHP() <= 0) {
			gameOver = true; //aqui va el gestor de escenes
		}

		Sleep(1000/ NUM_FPS);
		system("CLS");
	}
}



