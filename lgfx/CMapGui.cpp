#include "CMapGui.h"

CMapGui::CMapGui(IVideoDriver* &driver, gui::IGUIFont* &font) {
	myDriver = driver;
	myFont = font;
	myMapPos.x = 0; myMapPos.y = 0;
	
	//CMainMap myMainMap; // generujemy nowa mape;
	myMainMap.generateNewMap(); 
}
CMapGui::~CMapGui() {
	//delete myMainMap;
}

void CMapGui::loadData() {
	// Mapa główna
	myMapTex = myDriver->getTexture("data/gfx/map/world_map.jpg");
    myDriver->makeColorKeyTexture(myMapTex, core::position2d<s32>(0,0));
    
    // Miasta
	myVillageTex = myDriver->getTexture("data/gfx/map/village.png");
    myDriver->makeColorKeyTexture(myVillageTex, core::position2d<s32>(0,0));	
    myCastleTex = myDriver->getTexture("data/gfx/map/castle.png");
    myDriver->makeColorKeyTexture(myCastleTex, core::position2d<s32>(0,0));

	// Flagi
	myRedFlagTex = myDriver->getTexture("data/gfx/map/legion_flag_red.png");
    myDriver->makeColorKeyTexture(myRedFlagTex, core::position2d<s32>(0,0));    
}

void CMapGui::drawAll() {
	/*
	 * Rysujemy mape!
	 */
	this->drawMap();
	
	/*
	 * Rysujemy wszystkie okna z wektora, od końca. Te okna na końcu to są okna najwcześniej uruchomione
	 */
	 if (myWindows.size() > 0) {
		for (int counter = myWindows.size(); counter > 0 ; counter--) {
			myWindows.at(counter-1)->draw();
		}
	}
}

void CMapGui::drawMap() {
	// Rysujemy mape
		myDriver->draw2DImage(myMapTex, core::position2d<s32>(0, 0), core::rect<s32>(myMapPos.x, myMapPos.y,1024+myMapPos.x,768+myMapPos.y), 0, video::SColor(255,255,255,255), true);
	
	// Rysujemy miasta
	for (int i = 0; i < myMainMap.myCity.size(); i++) {
		SPoint pos = myMainMap.myCity.at(i).getPosition();
		if (myMainMap.myCity.at(i).getPopulation() < 800)
			myDriver->draw2DImage(myVillageTex, core::position2d<s32>(pos.x - myMapPos.x, pos.y - myMapPos.y), core::rect<s32>(0,0,25,25), 0, video::SColor(255,255,255,255), true);
		else
			myDriver->draw2DImage(myCastleTex, core::position2d<s32>(pos.x - myMapPos.x, pos.y - myMapPos.y), core::rect<s32>(0,0,20,30), 0, video::SColor(255,255,255,255), true);
	}
	// Rysujemy legiony
	for (int i = 0; i < myMainMap.myLegions.size(); i++) {
		SPoint pos = myMainMap.myLegions.at(i).getPosition();
		//std::cout << pos.x << " " << pos.y << " " << myMainMap.myLegions.at(i).getOwner() << std::endl;
		if (myMainMap.myLegions.at(i).getOwner() == 1 && myMainMap.myLegions.at(i).getState() == OK) {
			myDriver->draw2DImage(myRedFlagTex, core::position2d<s32>(pos.x - myMapPos.x, pos.y - myMapPos.y), core::rect<s32>(0,0,16,16), 0, video::SColor(255,255,255,255), true);
		}
	}
}

/*
 * Przesuwanie mapy klawiatura
 */
void CMapGui::moveMap(EKEY_CODE code) {
	//! przewijanie prawo/lewo
	if (code == irr::KEY_LEFT && myMapPos.x > 0 ) {
		myMapPos.x -= 3; //! przewijanie w lewo
	} else if (code == irr::KEY_RIGHT && myMapPos.x < 1024) {
		myMapPos.x += 3; //! przewijanie w prawo
	}
	//! przewijanie gora/dol
	if (code == irr::KEY_UP && myMapPos.y > 0 ) {
		myMapPos.y -= 3; //! przewijanie w górę
	} else if (code == irr::KEY_DOWN && myMapPos.y < 768) {
		myMapPos.y += 3; //! przewijanie w górę
	}
}

/* 
 * Przesuwanie mapy mysza (prawym przyciskiem mychy)
 */
void CMapGui::moveMap(int x, int y) {
	if (myMapPos.x - x >= 0 && myMapPos.x - x <= 1024) {
		myMapPos.x -= x;
	}
	if (myMapPos.y - y >= 0 && myMapPos.y - y <= 768) {
		myMapPos.y -= y;
	}
}

/*
 * Obsługa klikniec mysza
 */
int CMapGui::click(int x, int y) {
	// mamy jakies klikniecie w okno?
	for (int counter = 0; counter < myWindows.size(); counter++) {
		SPoint pos;
		pos.x = myWindows.at(counter)->getPosition().x;
		pos.y = myWindows.at(counter)->getPosition().y;
		pos.width = myWindows.at(counter)->getPosition().width;
		pos.height = myWindows.at(counter)->getPosition().height;
		
		// sprawdzamy czy bylo klikniecie w okno
		if (x > pos.x && x < pos.x+pos.width && y > pos.y && y < pos.y+pos.height) {
			int click = myWindows.at(counter)->click(x, y);
			if (click == button::OK) { // tutaj sprawdzamy w oknie czy bylo klikniecie w OK
				delete myWindows.at(counter);
				myWindows.erase(myWindows.begin() + counter);
				return true;
			} else if (click == button::ORDERS) {
				myWindows.at(counter)->legionOrders();
				return true;
			} else { 
				return false;
			}
		} 
	}
	
	/*
	 * Sprawdzamy czy było jakies kliknięcie na legion
	 */
	for (int counter = 0; counter < myMainMap.myLegions.size(); counter++) {
		// sprawdzamy czy bylo klikniecie na legion (z uwzglednieniem przesuniecia mapy)
		SPoint legionpos = myMainMap.myLegions.at(counter).getPosition();
		if (x > (legionpos.x - myMapPos.x) && x < (legionpos.x + legionpos.width) - myMapPos.x   
		 && y > (legionpos.y - myMapPos.y) && y < (legionpos.y + legionpos.height) - myMapPos.y) {
			//std::cout << "Klikniete " << myMainMap.myCity.at(counter).getName() << std::endl;
			CWindow* wnd = new CWindow(myDriver, myFont);
			wnd->legionInfo(myMainMap.myLegions.at(counter));
			myWindows.insert(myWindows.begin(), wnd);
			//myMainMap.myLegions.at(counter).setInfo(OPEN);
			
			return true;
		}
	}
	
	/*
	 * Sprawdzamy czy było jakies kliknięcie na miasto
	 */
	for (int counter = 0; counter < myMainMap.myCity.size(); counter++) {
		// sprawdzamy czy bylo klikniecie na miasto
		SPoint citypos = myMainMap.myCity.at(counter).getPosition();
		if (x > (citypos.x - myMapPos.x) && x < (citypos.x + citypos.width) - myMapPos.x   && y > (citypos.y - myMapPos.y) && y < (citypos.y + citypos.height) - myMapPos.y) {
//			std::cout << "Klikniete " << myMainMap.myCity.at(counter).getName() << std::endl;
			CWindow* wnd = new CWindow(myDriver, myFont);
			wnd->cityInfo(myMainMap.myCity.at(counter));
			myWindows.insert(myWindows.begin(), wnd);
		
			return true;
		}
	}
	return false;
}

void CMapGui::newDay() {
	myMainMap.newDay();
	for (int i = 0; i < myMainMap.myLegions.size(); i++) {
		if (myMainMap.myLegions.at(i).getState() == OK && myMainMap.myLegions.at(i).getFood() < 0) {
			// Skonczylo sie zarcie!
			CWindow *wnd = new CWindow(myDriver, myFont); 
			wnd->legionInfo(myMainMap.myLegions.at(i));
			myWindows.push_back(wnd);
		}
	}
	
}



