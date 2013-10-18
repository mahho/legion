#include "CAdventure.h"

CAdventure::CAdventure() {}
CAdventure::~CAdventure() {}

void CAdventure::createAdventure() {
    myType = rand() % 12; // losujemy jaka przygoda 
    
    // tu musimy uwzglednic jaka to przygoda, bo jesli szczerbiec, to gora, itp
    myPosition.x = rand() % 2000 + 24;
    myPosition.y = rand() % 1500 + 18;
}

