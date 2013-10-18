#include "CMainMap.h"

CMainMap::CMainMap() {
    numberOfCity = 50;
    myDay = 1;
    AI_PLAYERS = 3;
    
    redLegionsCnter = 0;
    blueLegionsCnter = 0;
    greenLegionsCnter = 0;
    yellowLegionsCnter = 0;
}

CMainMap::~CMainMap() {}

void CMainMap::generateNewMap() {
    
    /*
    // --------------------- Generowanie miast, do poprawy zapewne, kiedys :)
    // tworzymy pierwsze miasto byle gdzie
    CCity newCity;
    SPoint pos;
    pos.x = rand() % 1850 + 50;
    pos.y = rand() % 1400 + 50;
    newCity.setPosition(pos);
    myCity.push_back(newCity);
    
    // tworzymy 49 pozostalych miast i je odpowiednio ukladamy
    for (int counter = 1; counter < numberOfCity; counter++) {
	CCity newCity;

	SPoint pos;
	bool ok = false;
	while (ok == false) {
	    // losuemy pozycje dla miasta
	    pos.x = rand() % 2048;
	    pos.y = rand() % 1536;
	    
	    std::cout << counter  << " " << pos.x << " " << pos.y << std::endl;
	    // sprawdzamy czy jest jakies inne miasto w poblizu
	    for (int i=0; i < myCity.size(); i++) {
		SPoint cpos = myCity.at(i).getPosition();
//		std::cout << "cpos: " << cpos.x << " " << cpos.y << std::endl;
		if (cpos.x > pos.x + 100 || cpos.x < pos.x - 100) {
		    if (cpos.y > pos.y + 100 || cpos.y < pos.y - 100) {
			// nie ma? no to gitara
			ok = true;
		    }
		} 
	    }
	}
	
	newCity.setPosition(pos);
	myCity.push_back(newCity);	
    }
    */
    // czyscimy tablice
    for (int x = 0; x < 64; x++)
	for (int y = 0; y < 48; y++) 
	    myMap[x][y] = 0;
    
    std::cout << "[CMainMap] generuje mape..." << std::endl;
    int counter = 0; // licznik wygenerowanych miast
    while (counter < 40) {
	SPoint pos;
	pos.x = rand() % 60 + 2;
	pos.y = rand() % 44 + 2;
	if (myMap[pos.x][pos.y] == 0) {
	    if (myMap[pos.x-1][pos.y] == 0 && myMap[pos.x+1][pos.y] == 0 &&
		myMap[pos.x][pos.y-1] == 0 && myMap[pos.x][pos.y+1] == 0 && 
		myMap[pos.x+1][pos.y+1] == 0 && myMap[pos.x-1][pos.y+1] == 0 && 
		myMap[pos.x+1][pos.y-1] == 0 && myMap[pos.x-1][pos.y-1] == 0) // taki tam waruneczek do sprawdzania czy jest jakies miasto obok, mozna przerobic kiedys
		{
		    myMap[pos.x][pos.y] = counter;
		    CCity newCity;
		    SPoint newpos; newpos.x = pos.x*32; newpos.y = pos.y*32;
		    newCity.setPosition(newpos);
		    myCity.push_back(newCity);
		    counter++;
		}
	}
    }
    
    // ---------------------------------------- A tu juz legiony
    // tworzymy legion dla gracza
    CLegion newLegion;
    newLegion.createLegion(5);
    newLegion.setOwner(1);
    myLegions.push_back(newLegion);
    
    // tworzymy 9 legionow, dla kazdego kompa po 3
/*    for (int counter = 0; counter < 9; counter++) {
	CLegion newLegion;
	newLegion.createLegion(5);
	newLegion.setOwner((counter+3)/3 + 1);
	myLegions.push_back(newLegion);
    } */
    
    
}

void CMainMap::newDay() {
    myDay++;
	std::cout << "[CMainMap] newDay() " << std::endl;    
    // petla sprawdzajaca miasta
    for (int counter = 0; counter < myCity.size(); counter++) {
		myCity.at(counter).newTurn();
    }
    
    // petla sprawdzajaca legiony
    for (int counter = 0; counter < myLegions.size(); counter++) {
	std::cout << "Order? : " << myLegions.at(counter).getOrder() << std::endl;
	myLegions.at(counter).newTurn();
	
	int id = myLegions.at(counter).getOwner();
	SPoint myPosition = myLegions.at(counter).getPosition();

	
	if (id == 1) {
	    // gracz
//	    std::cout << "Legion gracza" << std::endl;
	} else if (id == 2) {
	    myAi1.checkOrders(myLegions.at(counter)); 
	} else if (id == 3) {
	    myAi2.checkOrders(myLegions.at(counter));
	} else if (id == 4) {
	    myAi3.checkOrders(myLegions.at(counter));
	} 
	
   }

    std::cout << "------- Dzien: " << myDay << std::endl;
}

// private
SPoint CMainMap::getNearestObject(SPoint myPosition, int owner) {
    bool found_something = false; // nic nie znalazlem
    int area = 50;
    SPoint poz;
    // pobieramy liste miast i sprawdzamy czy cos jest w poblizu
    while (found_something == false) {
	for (int counter = 0; counter < myCity.size(); counter++) {
	    if (myCity.at(counter).getOwner() != owner) {
		poz = myCity.at(counter).getPosition();
		if (poz.x > myPosition.x - area && poz.x < myPosition.x + area && poz.y > myPosition.y - area && poz.y < myPosition.y + area) { 
		    std::cout << "Znalazlem cel! -> " << myCity.at(counter).getName() << std::endl;
		    found_something = true;
		    break;
		}
	    } 
	}
	area += 50;
    }
    return poz;
}
