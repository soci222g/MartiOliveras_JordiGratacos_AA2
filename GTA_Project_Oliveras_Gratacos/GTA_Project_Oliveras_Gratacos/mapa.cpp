#include"mapa.h"
#include <fstream>
#include <iostream>
#include<vector>


Mapa::Mapa() {
	//lectura de archivos
	int widthFitx, heightFitx, nPeatones1, dineroPeaje1, maxDinPeaton1, nPeatones2, dineroPeaje2, maxDinPeaton2;
	char separator;
	std::ifstream configFile("config.txt");
	if (configFile.is_open())
	{
		configFile >> widthFitx >> separator >> heightFitx >> separator >> nPeatones1 >> separator >> dineroPeaje1 >> separator >> maxDinPeaton1 >> separator >> nPeatones2 >> separator >> dineroPeaje2 >> separator >> maxDinPeaton2;
		std::cout << widthFitx << " " << heightFitx << " " << nPeatones1 << " " << dineroPeaje1 << " " << maxDinPeaton1 << " " << nPeatones2 << " " << dineroPeaje2 << " " << maxDinPeaton2 << std::endl;
		configFile.close();
	}
	else
	{
		std::cout << "File ERROR." << std::endl;
	}
	//guardamos todas las variables
	width = widthFitx;
	heigh = heightFitx;
	N_peatones1 = nPeatones1;
	N_peatones2 = nPeatones2;
	precioPeaje1 = dineroPeaje1;
	precioPeaje2 = dineroPeaje2;
	maxDinero1 = maxDinPeaton1;
	maxDinero2 = maxDinPeaton2;


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

	//dividim mapa
	int columna_pared_1 = static_cast<int>(heigh * 0.33);
	int columna_pared_2 = static_cast<int>(heigh * 0.66);
	limitLeftMapa1 = columna_pared_1;
	limitLeftMapa2 = columna_pared_2;
	
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
	

	
}

void Mapa::addPlayerMapa(Player playerPos) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < heigh; j++) {

			if (j == playerPos.getVector().X && i == playerPos.getVector().Y) {
				mapa[i][j] = Cella::PLAYER;
			}
		}
	}
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
			if (mapa[i][j] == Cella::PEATON) {
				std::cout << " " << "P" << " ";
			}
		}
		std::cout << std::endl;
	}
}

void Mapa::addPeatonesMapa(std::vector<peaton> array_peatones, int size) {

	for (int k = 0; k < size; k++) {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < heigh; j++) {

				if (j== array_peatones[k].GetPosition().X && i == array_peatones[k].GetPosition().Y) {
					mapa[i][j] = Cella::PEATON;
				}
			}
		}
	}


}

Mapa::~Mapa() {

}
