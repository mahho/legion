#include "CBuilding.h"

CBuilding::CBuilding() {}
CBuilding::~CBuilding() {}

void CBuilding::createBuilding() {
    myType = rand() % 9;
    myPosition.x = rand() % 2048;
    myPosition.y = rand() % 1536;
    
    // wczytujemy wielkosc budynku z pliku
    
}
