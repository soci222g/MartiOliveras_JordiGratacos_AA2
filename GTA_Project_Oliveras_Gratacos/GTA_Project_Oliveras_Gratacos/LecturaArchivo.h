#include <fstream>
#include <iostream>


class LecturaArchivo
{
public:
	LecturaArchivo();



	int GetWidth() const { return width; }
	int GetHeigt() const { return height; }
	int GetnPeatones1() const { return nPeatones1; }
	int GetdineroPeaje1()const { return dineroPeaje1; }
	int GetmaxDinPeaton1()const { return maxDinPeaton1; }
	int GetnPeatones2() const { return nPeatones2; }
	int GetdineroPeaje2()const { return dineroPeaje2; }
	int GetmaxDinPeaton2()const { return maxDinPeaton2; }

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
