#include "CCity.h"

CCity::CCity() {
    myOwner = 0;
    myName = Tools::createName();
    myTax = rand() % 20;
    myMorale = rand() % 100 + 50;
    
    myPopulation = rand() % 900 + 10;
    if (myPopulation > 700)
	myWallType = rand() % 2 + 1;
    else
	myWallType = rand() % 1;
    
    myPriceModificators = rand() % 50;
        
    int how_many_buildings = rand() % 8; // losujemy ile budynkow
    for (int counter = 0; counter < how_many_buildings; counter++) {
	CBuilding newBuilding;
	newBuilding.createBuilding();
	myBuildings.push_back(newBuilding);
    }

    lastVisited = 0;    
}
CCity::~CCity() {
}

void CCity::setPosition(SPoint pos) {
    myPosition = pos;
    myPosition.width = 25;
    myPosition.height = 25;

}

void CCity::incTax() {
    if (myTax < 25)
	myTax++;
}

void CCity::decTax() {
    if (myTax > 0)
	myTax--;
}

void CCity::newTurn() {
    // i robimy im kilka wydarzen specjalnych
    if ((rand() % 50 == 1) && myPopulation > 800) {
        int plag = rand() % 3;
        if (plag == 0) {
            std::cout << "plomienie " << std::endl;
            myPopulation = myPopulation/4;
        } else if (plag == 1) {
            std::cout << "epidemia" << std::endl;
            myPopulation = myPopulation/2;
        } else if (plag == 2) {
            std::cout << "szczury" << std::endl;
        }
        std::cout << myPopulation << std::endl;
    }
    
    int szajba = myMorale / 10;
    myMorale += szajba - myTax; 
    myPopulation += szajba - myTax; 
    
    
    if (myMorale > 150)
	myMorale = 150;
    else if (myMorale < 0) {
	myMorale = 0;
	if (myOwner > 0) {
	    myOwner = 0;
	    std::cout << "BUNT! " << std::endl;
	}
	myMorale += rand() % 50 + 50;
	myTax -= rand() % 5 + 2;
    }

    if (myTax < 0)    
	myTax = 0;
	
    if (myPopulation < 30) 
	myPopulation = 30;
    
//    std::cout << myPopulation << " " << myMorale << std::endl;
}
