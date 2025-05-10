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
	Mapa(Vector playerPos);
	~Mapa();

	void printMapaTotal(Player jugador);



private:

	int width;
	int heigh;


	Cella** mapa;
};

