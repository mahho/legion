#ifndef __CAI_H_
#define __CAI_H_

#include "CLegion.h"
#include "CPlayerPattern.h"
#include "CCity.h"
#include "Tools.h"

class CAi : public CPlayerPattern {
    SPoint myTarget;
public:
    CAi();
    ~CAi();
    int checkOrders(CLegion &myLegion);

};

#endif
 