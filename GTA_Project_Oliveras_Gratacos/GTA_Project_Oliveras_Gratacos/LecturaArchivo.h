#include <fstream>
#include <iostream>


class LecturaArchivo
{
public:
	LecturaArchivo();



	int GetWidth() const { return width; }
	int GetHeigt() const { return height; }
	int GetHpCJ()const { return hpCJ; }
	int GetPowerCJ() { return powerCJ; }
	int GetdineroPeaje1()const { return dineroPeaje1; }
	int GetdineroPeaje2()const { return dineroPeaje2; }
	int GetnPeatones1() const { return nPeatones1; }
	int GetmaxDinPeaton1()const { return maxDinPeaton1; }
	int GethpPeatones1() const { return hpPeatones1; }
	int GetpowerPeatones1() const { return powerPeatones1; }
	int GetnPeatones2() const { return nPeatones2; }
	int GetmaxDinPeaton2()const { return maxDinPeaton2; }
	int GethpPeatones2() const { return hpPeatones2; }
	int GetpowerPeatones2() const { return powerPeatones2; }
	int GetnPeatones3() const { return nPeatones3; }
	int GetmaxDinPeaton3()const { return maxDinPeaton3; }
	int GethpPeatones3() const { return hpPeatones3; }
	int GetpowerPeatones3() const { return powerPeatones3; }
	int GetnCoche1() const { return nCoche1; }
	int GetnCoche2() const { return nCoche2; }
	int GetnCoche3() const { return nCoche3; }

private:


	int width;
	int	height;
	int hpCJ;
	int powerCJ;
	int	dineroPeaje1;
	int dineroPeaje2;
	int	nPeatones1;
	int maxDinPeaton1;
	int hpPeatones1;
	int powerPeatones1;
	int nPeatones2;
	int maxDinPeaton2;
	int hpPeatones2;
	int powerPeatones2;
	int nPeatones3;
	int maxDinPeaton3;
	int hpPeatones3;
	int powerPeatones3;
	int nCoche1;
	int nCoche2;
	int nCoche3;
};
