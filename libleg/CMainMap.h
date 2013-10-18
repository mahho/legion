#ifndef __CMAINMAP_H_
#define __CMAINMAP_H_

#include "CCity.h"
#include "CLegion.h"
#include "CAi.h"
#include "CPlayer.h"
#include "CSimulatedAction.h"
#include "CEventManager.h"
#include "CAdventure.h"

#include <vector>
#include <iostream>


class CMainMap {
    int AI_PLAYERS;
    

    int numberOfCity; // ilosc miast na mapie
    int myDay; // dzien;
    
    CPlayer myPlayer1; // gracz
    CAi myAi1; // komp1
    CAi myAi2; // komp2
    CAi myAi3; // komp4
    int myMap[64][48];
    
    int redLegionsCnter, blueLegionsCnter, greenLegionsCnter, yellowLegionsCnter;
    
    SPoint getNearestObject(SPoint myPosition, int owner); // szukamy najblizszego obiektu do ataku
public:
    CMainMap();
    ~CMainMap();
    std::vector <CCity> myCity; // lista miast
    std::vector <CLegion> myLegions; // lista legionow
    std::vector <CAdventure> myAdventures; // lista przygod
    
    void generateNewMap();
    void newDay(); //! NOWA TURA
    
    // listy 
    std::vector <CCity> getCity() { return myCity; }
    std::vector <CLegion> getLegions() { return myLegions; }
};

#endif
