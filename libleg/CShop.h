#ifndef __CSHOP_H_
#define __CSHOP_H_

#include "CItem.h"
#include <cstdlib>

class CShop {
    CItem *myItems[20];
        
public:
    CShop();
    ~CShop();
    void createShop(int type);
    int getItemType(int x, int y);
    
};

#endif
