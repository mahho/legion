#ifndef __CCITY_H_
#define __CCITY_H_

#include "CBuilding.h"
#include "SPoint.h"
#include "Tools.h"
#include "CShop.h"

#include <string>
#include <vector>
enum _CITY_MORALES {
    REBELS = 25,
    DISSATISFIED = 50,
    SUBJECTS = 75,
    LOYAL = 100,
    FANATICS = 125
};

    

class CCity {

    std::string myName; // nazwa miasta
    int myTax; // podatek
    int myPopulation; // ilosc mieszkancow
    int myWallType; // typ muru obronnego
    int myOwner; // id wlasciciela (0 - brak, 1-4 - gracz)
    int myMorale; // morale w miescie (0-99)
    int myPriceModificators; // modyfikatory cenowe
    int lastVisited;
    SPoint myPosition;
    SPoint mySize;
    int myGround[64][48]; // ilosc miejsca na ziemii dla przedmiotow
    
    std::vector <CBuilding> myBuildings;
    
public:
    CCity();
    ~CCity();
    std::vector <CBuilding> getBuildings() { return myBuildings; }
    std::string getName() const { return myName; }
    int getTax() const { return myTax; }
    int getPopulation() const { return myPopulation; }
    void setPopulation(int newPopulation) { myPopulation = newPopulation; }
    int getWallType() const { return myWallType; }
    int getOwner() const { return myOwner; }
    void setOwner(int newOwner) { myOwner = newOwner; }
    int getMorale() const { return myMorale; }
    SPoint getPosition() const { return myPosition; }
    void setPosition(SPoint pos);
    void addPopulation() { myPopulation += rand() % 10; }

    int getLastVisited() const { return lastVisited; } // kiedy ostatnio byl legion jakis w miescie?
    void setVisited(int day) { lastVisited = day; } // wizytacja!
    // 
    void incTax();
    void decTax();
    void newTurn();
};


#endif

