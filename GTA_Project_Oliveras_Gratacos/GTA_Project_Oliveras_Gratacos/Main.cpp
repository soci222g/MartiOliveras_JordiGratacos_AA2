
#include <fstream>
#include <iostream>
#include<Windows.h>


#include"mapa.h"
#include"player.h"
#include"peaton.h"
#include"Coches.h"
#include"BigSmoke.h"

void instanciateGame(Player& newPlayer, Mapa& newMapa, BigSmoke& newBigSmoke, std::vector<peaton>& newPeatones, std::vector<Coches>& newCotxes) {
	

	Player player;
	Mapa mapa;
	BigSmoke BS(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight());

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


	for (int i = 0; i < SavePeatones.size(); i++) {
		mapa.addPeatoneMapa(SavePeatones[i]);
	}

	newPlayer = player;
	newMapa = mapa;
	newBigSmoke = BS;
	newPeatones = SavePeatones;
	newCotxes = cotxes;
}


int main()
{
	srand(time(NULL));
	
	Player player;
	Mapa mapa;
	BigSmoke BS(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight());


	

	std::vector<peaton> SavePeatones;
	// +1 per el id
	

	

	std::vector<Coches> cotxes;

	


	bool gameOver = false;
	bool InMenu = true;
	bool GamePlay = false;
	bool EndGame = false;
	const int NUM_FPS = 60;


	//info para el menu
	int menuNumPosiiton = 0;
	int currentTimerEnd = 10;
	while (!gameOver)
	{
		
		while (InMenu)
		{
			if (GetAsyncKeyState(VK_UP)) {
				if (menuNumPosiiton == 1) {
					menuNumPosiiton = 0;
				}
				else if (menuNumPosiiton == 0) {
					menuNumPosiiton = 1;
				}
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				if (menuNumPosiiton == 1) {
					menuNumPosiiton = 0;
				}
				else if (menuNumPosiiton == 0) {
					menuNumPosiiton = 1;
				}
			}
			if (GetAsyncKeyState(VK_SPACE)) {
				if (menuNumPosiiton == 0) {
					InMenu = false;
					GamePlay = true;
					currentTimerEnd = 200;
					
					instanciateGame(player, mapa, BS, SavePeatones, cotxes);

				}
				else if (menuNumPosiiton == 1) {
					gameOver = true;
					InMenu = false;
				}
			}

			if (menuNumPosiiton == 0) {
				std::cout << "START <-" << std::endl;
			}
			else {
				std::cout << "START" << std::endl;
			}

			if (menuNumPosiiton == 1) {
				std::cout << "Exit <-" << std::endl;
			}
			else {
				std::cout << "Exit" << std::endl;
			}	

			Sleep(1000 / NUM_FPS);
			system("CLS");
		}

		while (GamePlay) {
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
					if (!player.GetInCar()) {
						player.AtackPeaton(SavePeatones[i], mapa);
						SavePeatones[i].SeeIFDead();
						if (SavePeatones[i].getAlive() == false) {
							mapa.GenerateCoin(SavePeatones[i].GetPosition());
							SavePeatones[i].RespawnPeaton(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight(), i, mapa);
						}
					}
				}
				if (!player.GetInCar()) {
					player.AtackBigSmoke(BS, mapa);
					BS.SeeIFDead();
					if (BS.getAlive() == false) {
						GamePlay = false;
						EndGame = true;
					}
				}

				mapa.generateEmpty(player.getVector());
			}
			else if (GetAsyncKeyState(VK_ESCAPE))
			{
				InMenu = true;
				GamePlay = false;
			}
			else if (GetAsyncKeyState('E'))
			{

				if (player.GetcanEnterCar() && !player.GetInCar())
				{
					mapa.SetCella(player.getVector().X, player.getVector().Y, Cella::VACIA);
					player.setPlVector(player.getVectorCar());
					player.setInCarTrue();
					player.setFcanEnterCar();
				}
				else if (player.GetInCar())
				{

				}
				mapa.generateEmpty(player.getVector());
			}
			else
			{
				player.setMoveInput(Actions::NONE);
			}

			//UPDATE
			player.SeeIfCanMove(mapa, GamePlay, EndGame);

			if (player.GetCanMove() == true) {
				player.Reed_input(player.getMoveInput());
			}

			if (!player.GetInCar())
			{
				for (int i = 0; i < cotxes.size(); i++)
				{
					player.EnterCar(cotxes[i], i);
				}
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

			if (player.GetHP() <= 0) {
				GamePlay = false;
				EndGame = true;
			}



			mapa.addPlayerMapa(player);

			mapa.PayPeaje(player);




			//mapa.printPlayerView(player);



			mapa.printMapaTotal(player);
			if (player.GetHP() <= 0) {
				GamePlay = false;
				EndGame = true;
			}

			Sleep(1000 / NUM_FPS);
			system("CLS");
		}


		while (EndGame) {
			
			if (currentTimerEnd <= 0) {
				EndGame = false;
				InMenu = true;
			}
			else {
				currentTimerEnd--;
			}


			std::cout << "------------------GAME OVER-----------------";
			
			
			
			
			Sleep(1000 / NUM_FPS);
			system("CLS");
		}
	}

		//INPUTS
		
}



