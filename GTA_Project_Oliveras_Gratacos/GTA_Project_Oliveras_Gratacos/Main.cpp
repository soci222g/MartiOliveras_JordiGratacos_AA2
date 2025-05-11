
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
	
	mapa.addPlayerMapa(player);
	int pasAddMapa = 0;
	for (int i = 0; i < SavePeatones.size(); i++) {
		mapa.addPeatoneMapa(SavePeatones[i]);
		pasAddMapa++;
	}
	

	//mapa.printMapaTotal(player);
	//mapa.printPlayerView(player);
	


}
