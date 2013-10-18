#include "CAi.h"

CAi::CAi() {
    myName = Tools::createName();
    myTarget.x = 1;
    myTarget.y = 1;
}

CAi::~CAi() {}

int CAi::checkOrders(CLegion &myLegion) {
    std::cout << "[CAi] Sprawdzam rozkazy..." << std::endl;
    if (myLegion.getDaysOfFood() <= 3) {
	myLegion.setOrder(HUNT_ORDER);
    }
    // mamy zarlo, mamy energie, wiec szukamy celu!
    else if (myLegion.getStrength() > 100) {
	myLegion.goTo(myTarget.x, myTarget.y, MOVE_ORDER);
	myLegion.setOrder(MOVE_ORDER);
    }
}
