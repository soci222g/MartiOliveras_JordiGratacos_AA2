#include"mapa.h"
#include <fstream>
#include <iostream>

Mapa::Mapa(int Width, int Heigh, Vector playerPos) {
	//lectura de archivos



	width = Width;
	heigh = Heigh;


	mapa = new Cella * [width];

	for (int i = 0; i < width; i++)
	{
		mapa[i] = new Cella[heigh];
	}
	//full map _vacio
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < heigh; j++) {

			mapa[i][j] = Cella::VACIA;
		}
	}
	int columna_pared_1 = static_cast<int>(heigh * 0.33);
	int columna_pared_2 = static_cast<int>(heigh * 0.66);
	
	
	for (int i = 0; i < width; i++) {
		for (int j = 0;  j < heigh; j++) {
			
			if (j == columna_pared_1 || j == columna_pared_2) {
				mapa[i][j] = Cella::PARED;
			}
		}
	}
	for (int i = 0; i < heigh; i++)
	{
		mapa[0][i] = Cella::PARED;
		mapa[width-1][i] = Cella::PARED;
	}
	//setup_paredes verticales
	for (int j = 0; j < width; j++)
	{
		mapa[j][0] = Cella::PARED;
		mapa[j][heigh - 1] = Cella::PARED;
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < heigh; j++) {

			if (i == playerPos.X && j == playerPos.Y) {
				mapa[i][j] = Cella::PLAYER;
			}
		}
	}

	
}


Mapa::~Mapa() {

}

void Mapa::printMapaTotal(Player jugador) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < heigh; j++) {
			if (mapa[i][j] == Cella::VACIA) {
				std::cout << " " << " " << " ";
			}
			if (mapa[i][j] == Cella::PLAYER) {
				if (jugador.getMoveInput() == Movement::UP) {
					std::cout << " " << "^" << " ";
				}
				if (jugador.getMoveInput() == Movement::DOWM) {
					std::cout << " " << "v" << " ";
				}
				if (jugador.getMoveInput() == Movement::LEFT) {
					std::cout << " " << "<" << " ";
				}
				if (jugador.getMoveInput() == Movement::RIGHT) {
					std::cout << " " << ">" << " ";
				}
			}
			if (mapa[i][j] == Cella::PARED) {
				std::cout << " " << "X" << " ";
			}
		}
		std::cout << std::endl;
	}
}
