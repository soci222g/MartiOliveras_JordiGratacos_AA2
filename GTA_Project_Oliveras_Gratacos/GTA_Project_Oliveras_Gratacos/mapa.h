#pragma once
#include"Vector.h"
#include"player.h"
#include"peaton.h"
#include<vector>

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
	Mapa();
	~Mapa();
	
	void addPlayerMapa(Player player);

	void generateEmpty(Vector position);
	
	void addPeatoneMapa(peaton peaton);

	void printMapaTotal(Player jugador);

	void printPlayerView(Player jugador);
	//hacer geters de todo

	int getHeight() { return heigh; }

	Cella getCella(int x, int y) { return mapa[x][y]; }

	int GetN_peatones1() { return N_peatones1; }
	int GetN_peatones2() { return N_peatones2; }

	int getLimitLeftMapa1() { return limitLeftMapa1; }
	int getLimitLeftMapa2() { return limitLeftMapa2; }


private:

	 int width;
	 int heigh;

	int N_peatones1;
	int N_peatones2;
	int precioPeaje1;
	int precioPeaje2;
	int maxDinero1;
	int maxDinero2;


	int apreturaIsla1;
	int apreturaIsla2;

	 int limitLeftMapa1;
	int limitLeftMapa2;

	Cella** mapa;
};

