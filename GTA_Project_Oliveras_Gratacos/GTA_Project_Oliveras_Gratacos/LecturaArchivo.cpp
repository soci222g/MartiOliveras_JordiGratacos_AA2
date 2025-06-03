#include"lecturaArchivo.h"

LecturaArchivo::LecturaArchivo()
{
	char separator;
	std::ifstream configFile("config.txt");
	if (configFile.is_open())
	{
		configFile >> width >> separator >> height >> separator >> hpCJ >> separator >> powerCJ >> separator >> dineroPeaje1 >> separator >> dineroPeaje2 >> separator >>
			nPeatones1 >> separator >> maxDinPeaton1 >> separator >> hpPeatones1 >> separator >> powerPeatones1 >> separator >>
			nPeatones2 >> separator >> maxDinPeaton2 >> separator >> hpPeatones2 >> separator >> powerPeatones2 >> separator >> 
			nPeatones3 >> separator >> maxDinPeaton3 >> separator >> hpPeatones3 >> separator >> powerPeatones3 >> separator >>
			nCoche1 >> separator >> nCoche2 >> separator >> nCoche3;
		configFile.close();
	}
	else
	{
		std::cout << "File ERROR." << std::endl;
	}
}

