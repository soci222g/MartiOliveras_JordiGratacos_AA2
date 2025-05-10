#pragma once
#include"Vector.h"
#include"player.h"

enum class Cella
{
	VACIA,
	PEATON,
	PARED,
	PLAYER,
	DINERO,
	COUNT
};


class Mapa
{
public:
	Mapa(int width, int heigh, Vector playerPos);
	~Mapa();

	void printMapaTotal(Player jugador);



private:

	int width;
	int heigh;


	Cella** mapa;
};

