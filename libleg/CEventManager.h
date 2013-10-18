#ifndef __CEVENTMANAGER_H_
#define __CEVENTMANAGER_H_

#include "CLegion.h"
#include <vector>

class CEventManager {

public:
    CEventManager();
    ~CEventManager();
    void huntEvent(CLegion &myLegion);
};

extern std::vector <CEventManager> myEvents;

#endif
