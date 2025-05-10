
#include <fstream>
#include <iostream>

#include"mapa.h"
#include"player.h"

int main()
{
	Player player;

	Mapa mapa(player.getVector());
	mapa.printMapaTotal(player);

}
