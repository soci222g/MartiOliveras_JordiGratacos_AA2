
#include <fstream>
#include <iostream>
#include<Windows.h>

#include"mapa.h"
#include"player.h"
#include"peaton.h"



int main()
{
	
	Player player;

	Mapa mapa;
	
	
	
	
	peaton peatones(mapa.getLimitLeftMapa1(), mapa.getLimitLeftMapa2(), mapa.getHeight(), 1);

	mapa.addPlayerMapa(player);

	

	mapa.printMapaTotal(player);




}
