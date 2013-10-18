#ifndef __CMAPGUI_H_
#define __CMAPGUI_H_

#include <irrlicht/irrlicht.h>

//#include "CButton.h"
#include "CWindow.h"
#include "../libleg/libleg.h"

class CMapGui {

	std::vector <CWindow*> myWindows;
	CMainMap myMainMap; // dane
	SPoint myMapPos;
	
	video::ITexture *myMapTex; // tekstura dla mapy glownej
	video::ITexture *myVillageTex, *myCastleTex; // tekstury dla miast
	video::ITexture *myRedFlagTex, *myBlueFlagTex, *myGreenFlagTex, *myYellowFlagTex; // tekstury - flagi

	IVideoDriver *myDriver;
	gui::IGUIFont *myFont;

	void drawMap();	 // rysowanie mapy
public:
	CMapGui(IVideoDriver* &driver, gui::IGUIFont* &font);
	void loadData();
	~CMapGui();

	void drawAll(); 	// rysowanie wszystkiego
	
	int click(int x, int y);
//	std::vector <CWindow> getWindows() { return myWindows; }
	CMainMap getMainMap() { return myMainMap; }
	
	void moveMap(EKEY_CODE code);
	void moveMap(int x, int y);
	void newDay();
	


};

#endif
