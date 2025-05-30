#include"lecturaArchivo.h"

LecturaArchivo::LecturaArchivo()
{
	char separator;
	std::ifstream configFile("config.txt");
	if (configFile.is_open())
	{
		configFile >> width >> separator >> height >> separator >> nPeatones1 >> separator >> dineroPeaje1 >> separator >> maxDinPeaton1 >> separator >> nPeatones2 >> separator >> dineroPeaje2 >> separator >> maxDinPeaton2;
		//std::cout << widthFitx << " " << heightFitx << " " << nPeatones1 << " " << dineroPeaje1 << " " << maxDinPeaton1 << " " << nPeatones2 << " " << dineroPeaje2 << " " << maxDinPeaton2 << std::endl;
		configFile.close();
	}
	else
	{
		std::cout << "File ERROR." << std::endl;
	}
}

