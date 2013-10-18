#include "CShop.h"

CShop::CShop() {
    for (int i=0; i<20; i++) {
	myItems[i] = 0;
    }
}
CShop::~CShop() {
}

void CShop::createShop(int type) {
    for (int i=0; i<20; i++) {
	if (rand() % 10 > 5) {
	    myItems[i] = new CItem();
	    myItems[i]->createItem();
	} 
    } 
}

int CShop::getItemType(int x, int y) {
}

