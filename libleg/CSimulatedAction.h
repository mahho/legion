#ifndef __CSIMULATEDACTION_H_
#define __CSIMULATEDACTION_H_

#include <iostream>
#include "CLegion.h"
#include "CCity.h"

class CSimulatedAction {

public:
    CSimulatedAction();
    ~CSimulatedAction();
    int doHunt();
    void doCityAttack();
    void doLegionsFight();
};

#endif
