#ifndef __CBUILDING_H_
#define __CBUILDING_H_

#include "Tools.h"
#include "SPoint.h"

enum _building_type {
    WELL = 0, 	// studnia
    GALLOWS = 1,// szubienica
    BARREL = 2, // beczka
    SHOP = 3, 	// sklep
    ARMORY = 4, // zbrojownia
    TEMPLE = 5, // swiatynia
    HUNTER = 6, // mysliwy
    ALCHEMIST = 7, // alchemik
    GRANARY = 8, // spichlerz
};

class CBuilding {

    int myType; // typ budynku
    SPoint myPosition; // pozycja
    
public:
    CBuilding();
    ~CBuilding();
    int getType() const { return myType; }
    SPoint getPosition() const { return myPosition; }
    void createBuilding();
};

#endif
