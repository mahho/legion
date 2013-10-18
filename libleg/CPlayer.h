#ifndef __CPLAYER_H_
#define __CPLAYER_H_

#include "CLegion.h"
#include "CPlayerPattern.h"
#include "CCity.h"
#include "Tools.h"

class CPlayer : public virtual CPlayerPattern {
public:
    CPlayer();
    ~CPlayer();
    void checkOrders(CLegion &myLegion);
};

#endif
 