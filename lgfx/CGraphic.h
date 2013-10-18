#ifndef __CGRAPHIC_H_
#define __CGRAPHIC_H_

//#ifdef MINGW
    #include <irrlicht/irrlicht.h>
//#else
//    #include <irrlicht.h>
//#endif

#include <iostream>
#include "CMapGui.h"
#include "CEventReceiver.h"

#include "../libleg/libleg.h"

class CGraphic {
	IrrlichtDevice *device;
	IVideoDriver *driver;

	
	//CGui *myGui;
	
	CMapGui *myMapGui;
	CEventReceiver myEventReceiver;
	//CMainMap &myMainMap;
	
	u32 then;
	//std::vector <CWindow *> myWindows;

	float myKeyEventTimer, myClickEventTimer;
	bool needRefresh;
	bool quit;
	
	SPoint clicked;
	SPoint oldclicked;
public:
    CGraphic();
    ~CGraphic();
    void init();
    void draw();
    void connectData(CMainMap* &mmap);
    void close();
    void animateLegionMove(SPoint from, SPoint to);
	int clickEvent();
	int keypressedEvent();

    int getKeyEvent();
    int getMouseEvent();

};

#endif

