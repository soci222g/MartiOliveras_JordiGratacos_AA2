
#include <fstream>
#include <iostream>

#include"mapa.h"
#include"player.h"

int main()
{
	int x = 10;
	int y = 20;

	Player player;

	Mapa mapa(x,y, player.getVector());
	mapa.printMapaTotal(player);

}
