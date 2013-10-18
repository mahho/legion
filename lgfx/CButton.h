#ifndef __CBUTTON_H_
#define __CBUTTON_H_

#include "SPoint.h"

#include <vector>
//#ifdef MINGW
    #include <irrlicht/irrlicht.h>
//#else
//    #include <irrlicht.h>
//#endif
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace button {
	enum _buttonType {
		EXIT = 0,
		OK = 1,
		ORDERS = 2,
		MOVE_ORDER = 3,
		FAST_MOVE_ORDER = 4,
		ATTACK_ORDER = 5,
		HUNT_ORDER = 6,
		CAMP_ORDER = 7,
		EQUIPMENT = 8,
		ACTION_IN_TERRAIN = 9
	};
};

class CButton {
	int myType; // typ przycisku
	
public:
	CButton();
	~CButton();
	video::ITexture* myTexture;
	SPoint myPosition; //! pozycja x/y + wysokosc/szerokosc
	void setProperties(SPoint pos, int type);
	int getType() const { return myType; }
	SPoint getPos() const { return myPosition; }
	bool visible;
	
};

#endif
