#include "CSimulatedAction.h"

CSimulatedAction::CSimulatedAction() {}
CSimulatedAction::~CSimulatedAction() {}

int CSimulatedAction::doHunt() {
    int r = rand() % 8;
    std::cout << "Rand: " << r << std::endl;
    if (r < 5) {
	std::cout << "dzik" << std::endl;
    } else if (r >= 5 && r < 8) {
	std::cout << "wilk" << std::endl;
    }
    int ile = rand() % 9 + 1;
    return ile*17;
}

void CSimulatedAction::doCityAttack() {
}

void CSimulatedAction::doLegionsFight() {
}

            