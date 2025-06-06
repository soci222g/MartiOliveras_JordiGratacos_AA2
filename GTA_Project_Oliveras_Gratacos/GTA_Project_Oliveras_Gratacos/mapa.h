#pragma once
#include"Vector.h"
#include"player.h"
#include"peaton.h"
#include"Coches.h"
#include"BigSmoke.h"
#include<vector>

enum class Cella
{
	VACIA,
	PEATON,
	PARED,
	PLAYER,
	DINERO,
	COCHE,
	PEAJE,
	BIG_SMOKE,
	COUNT
};

class Player;
class BigSmoke;
class peaton;

class Mapa
{
public:
	Mapa();
	~Mapa();
	
	void addPlayerMapa(Player player);


	void generateEmpty(Vector position);

	void GenerateCoin(Vector position);
	
	void addPeatoneMapa(peaton peaton);
	void addBigSmokeMapa(BigSmoke BS);
	void addCocheMapa(Coches coche);

	void printMapaTotal(Player jugador);

	void printPlayerView(Player jugador);
	//hacer geters de todo

	int getHeight() { return heigh; }
	int getWidth() { return width; }


	Cella getCella(int x, int y) { return mapa[y][x]; }

	void SetCella(int x, int y, Cella cell) { mapa[y][x] = cell; }

	void PayPeaje(Player& jugador);


	int GetN_peatones1() { return N_peatones1; }
	int GetN_peatones2() { return N_peatones2; }
	int GetN_peatones3() { return N_peatones3; }

	int getLimitLeftMapa1() { return limitLeftMapa1; }
	int getLimitLeftMapa2() { return limitLeftMapa2; }

	int GetNCarI1() { return nCarI1; }
	int GetNCarI2() { return nCarI2; }
	int GetNCarI3() { return nCarI3; }


	int GetMaxDineroIsla1() { return maxDinero1; }
	int GetMaxDineroIsla2() { return maxDinero2; }
	int GetMaxDineroIsla3() { return maxDinero3; }
private:

	 int width;
	 int heigh;

	int N_peatones1;
	int N_peatones2;
	int N_peatones3;
	int precioPeaje1;
	int precioPeaje2;
	int maxDinero1;
	int maxDinero2;
	int maxDinero3;
	int nCarI1;
	int nCarI2;
	int nCarI3;

	int apreturaIsla1;
	int apreturaIsla2;

	int limitLeftMapa1;
	int limitLeftMapa2;

	bool peaje1;
	bool peaje2;


	Cella** mapa;
};

