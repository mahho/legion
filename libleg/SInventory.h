#ifndef __SINVENTORY_H_
#define __SINVENTORY_H_

#include "CItem.h"

struct SInventory {
    CItem head; 		// glowa
    CItem left_hand;	// lewa reka
    CItem right_hand;	// prawa reka
    CItem chest;		// klata
    CItem legs;		// nogi
    CItem backpack[2][4];	// plecak
};

#endif 