#include <fstream>
#include <iostream>


class LecturaArchivo
{
public:
	LecturaArchivo();



	int GetWidth() { return width; }
	int GetHeigt() { return height; }
	int GetnPeatones1() { return nPeatones1; }
	int GetdineroPeaje1() { return dineroPeaje1; }
	int GetmaxDinPeaton1() { return maxDinPeaton1; }
	int GetnPeatones2() { return nPeatones2; }
	int GetdineroPeaje2() { return dineroPeaje2; }
	int GetmaxDinPeaton2() { return maxDinPeaton2; }

private:


	int width;
	int	height;
	int	nPeatones1;
	int	dineroPeaje1;
	int maxDinPeaton1;
	int nPeatones2;
	int dineroPeaje2;
	int maxDinPeaton2;
};
