#pragma once

enum class Cella
{
	VACIA,
	PEATON,
	PARED,
	DINERO,
	COUNT
};


class Mapa
{
public:
	Mapa(int width, int heigh);
	~Mapa();

	void printMapaTotal();



private:

	int width;
	int heigh;


	Cella** mapa;
};

