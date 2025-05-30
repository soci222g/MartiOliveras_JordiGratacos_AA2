#include"mapa.h"
#include"lecturaArchivo.h"
#include<vector>


Mapa::Mapa() {
	//lectura de archivos
	LecturaArchivo archivo;
	//guardamos todas las variables
	width = archivo.GetWidth();
	heigh = archivo.GetHeigt();
	N_peatones1 = archivo.GetnPeatones1();
	N_peatones2 = archivo.GetnPeatones2();
	precioPeaje1 = archivo.GetdineroPeaje1();
	precioPeaje2 = archivo.GetdineroPeaje2();
	maxDinero1 = archivo.GetmaxDinPeaton1();
	maxDinero2 = archivo.GetmaxDinPeaton2();


	mapa = new Cella* [heigh];

	for (int i = 0; i < heigh; i++)
	{
		mapa[i] = new Cella[width];
	}
	//full map _vacio
	for (int i = 0; i < heigh; i++) {
		for (int j = 0; j < width; j++) {

			mapa[i][j] = Cella::VACIA;
		}
	}

	//dividim mapa
	int columna_pared_1 = static_cast<int>(width * 0.33);
	int columna_pared_2 = static_cast<int>(width * 0.66);
	limitLeftMapa1 = columna_pared_1;
	limitLeftMapa2 = columna_pared_2;


	apreturaIsla1 =  (rand() % heigh - 2) + 1;
	apreturaIsla2 =  (rand() % heigh - 2) + 1;

	for (int i = 0; i < heigh; i++) {
		for (int j = 0;  j < width; j++) {
			
			if (j == limitLeftMapa1 || j == limitLeftMapa2) {
				mapa[i][j] = Cella::PARED;
				if (i == apreturaIsla1 && j == limitLeftMapa1 || i == apreturaIsla2 && j == limitLeftMapa2) {
					mapa[i][j] = Cella::VACIA;
				}
			}
		}
	}

	for (int i = 0; i < width; i++)
	{

		mapa[0][i] = Cella::PARED;
		mapa[heigh - 1][i] = Cella::PARED;
	}
	//setup_paredes verticales
	for (int j = 0; j < heigh; j++)
	{
		mapa[j][0] = Cella::PARED;
		mapa[j][width - 1] = Cella::PARED;
	}
	

	
}



void Mapa::printMapaTotal(Player jugador) {
	for (int i = 0; i < heigh; i++) {
		for (int j = 0; j < width; j++) {
			if (mapa[i][j] == Cella::VACIA) {
				std::cout << " " << " " << " ";
			}
			if (mapa[i][j] == Cella::PLAYER) {
				if (jugador.getLastMoveInput() == Actions::UP) {
					std::cout << " " << "^" << " ";
				}
				if (jugador.getLastMoveInput() == Actions::DOWN) {
					std::cout << " " << "v" << " ";
				}
				if (jugador.getLastMoveInput() == Actions::LEFT) {
					std::cout << " " << "<" << " ";
				}
				if (jugador.getLastMoveInput() == Actions::RIGHT) {
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

void Mapa::printPlayerView(Player player) {
	for (int i = player.getVector().Y - player.GetVista(); i < player.getVector().Y + player.GetVista(); i++) {
		for (int j = player.getVector().X - player.GetVista(); j < player.getVector().X + player.GetVista(); j++) {
			if (i < 0 || j < 0 || i >= heigh || j >= width) {
				continue;
			}
			
			
			if (mapa[i][j] == Cella::VACIA) {
				std::cout << " " << " " << " ";
			}
			if (mapa[i][j] == Cella::PLAYER) {
				if (player.getLastMoveInput() == Actions::UP) {
					std::cout << " " << "^" << " ";
				}
				if (player.getLastMoveInput() == Actions::DOWN) {
					std::cout << " " << "v" << " ";
				}
				if (player.getLastMoveInput() == Actions::LEFT) {
					std::cout << " " << "<" << " ";
				}
				if (player.getLastMoveInput() == Actions::RIGHT) {
					std::cout << " " << ">" << " ";
				}
			}
			if (mapa[i][j] == Cella::PARED) {
				std::cout << " " << "X" << " ";
			}
			if (mapa[i][j] == Cella::PEATON) {
				std::cout << " " << "P" << " ";
			}
			if (mapa[i][j] == Cella::DINERO) {
				std::cout << " " << "$" << " ";
			}
			

		}
		std::cout << std::endl;
	}
}

void Mapa::addPlayerMapa(Player playerPos) {
	for (int i = 0; i < heigh; i++) {
		for (int j = 0; j < width; j++) {

			if (j == playerPos.getVector().X && i == playerPos.getVector().Y) {
				mapa[i][j] = Cella::PLAYER;
			}
		}
	}
}

void Mapa::generateEmpty(Vector position) {
	for (int i = 0; i < heigh; i++) {
		for (int j = 0; j < width; j++) {

			if (j == position.X && i == position.Y) {
				mapa[i][j] = Cella::VACIA;
			}
		}
	}
}

void Mapa::addPeatoneMapa(peaton peatones) {
	
		for (int i = 0; i < heigh; i++) {
			for (int j = 0; j < width; j++) { 
				if (peatones.GetPosition().X == j && peatones.GetPosition().Y == i) {
					mapa[i][j] = Cella::PEATON;
					//std::cout << peatones.getID() << std::endl;
					break;
				}
			}	
		}

}

Mapa::~Mapa() {

}
