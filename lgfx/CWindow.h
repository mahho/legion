#ifndef __CWINDOW_H_
#define __CWINDOW_H_

//#ifdef MINGW
    #include <irrlicht/irrlicht.h>
//#else
//    #include <irrlicht.h>
//#endif

#include "../libleg/libleg.h"
#include "CButton.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace window {
	enum window_type {
		INFO = 0,
		WARNING = 1,
		LEGION_ORDERS = 2,
		CITY_ORDERS = 3
	};
}

class CWindow {
	IVideoDriver* myDriver;
	video::ITexture* myImage;
	SPoint myPosition;

	gui::IGUIFont* myFont;
	
	std::string myName;
	CButton myOkButton;
	CButton myOrdersButton;
	
	CLegion myLegion;
	CCity myCity;
	
	int myType; // typ okna (info, menu, czy inne)
public:
	CWindow(IVideoDriver* &driver, gui::IGUIFont* &font);
	~CWindow();
	void create();
	void legionInfo(CLegion &legion);
	void legionOrders();
	void cityInfo(CCity &city);
	void cityOrders(CCity &city);
	void draw();
	int click(int x, int y); // klikniecie w okno (lub odpowiedni button)
	SPoint getPosition() const { return myPosition; }

	CCity getCity() const { return this->myCity; }
	CLegion getLegion() const { return this->myLegion; }
	int getType() const { return myType; }
};

#endif
