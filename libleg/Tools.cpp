#include "Tools.h"

namespace Tools {
    std::string createName()
    {
	std::string samogloski[10] = { "a","e","i","o","u","i","a","a","e","o" };
	std::string spolgloski[30] = { "c","f","h","k","p","s","t","p","j","s","s","k","t","p","t", "b","d","g","l","m","n","r","w","z","r","r","r","d","z","b" };
	std::string imie;
	int dlugosc = rand()%3+2;

	for (int i = 0; i <= dlugosc; i++)
	{
		std::string sam = samogloski[rand()%10];
		std::string spl = spolgloski[rand()%30];
		int a = rand()%3;
		if (a == 0) {
			imie = imie+sam;
			imie = imie+spl;
		} else if (a == 1) {
			imie = imie+spl;
			imie = imie+sam;
		} else if (a == 2)
			imie = imie+sam;
	}

 	char L = toupper(imie.at(0)); // zabiera pierwsza literke z imie i zamienia ja na wielka
	std::string R = imie.erase(0,1); // usuwa pierwsza literke z imie
	imie = L+R; // laczy to wyzej.
	return imie;
    }
}
