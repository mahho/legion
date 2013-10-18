#include "CGraphic.h"

CGraphic::CGraphic() {}
CGraphic::~CGraphic() {}

void CGraphic::init() {
    device = createDevice( video::EDT_OPENGL, dimension2d<u32>(1024, 768), 16, false, false, false, &myEventReceiver);
    device->setWindowCaption(L"Legion PC");
    
	quit = false;

    driver = device->getVideoDriver();
	gui::IGUIFont* font = device->getGUIEnvironment()->getFont("data/fonts/fontlucida.png");
	if (!font)
		std::cout << "Nie udało sie wczytac czcionki" << std::endl;
	
	//! wiadomo po co
	int lastFPS = -1;
	then = device->getTimer()->getTime();
	const f32 MOVEMENT_SPEED = 5.f;

	// Tworzymy nowa mape i dorzucamy jej sterownik grafiki
	myMapGui = new CMapGui(driver, font);
	myMapGui->loadData(); // wczytujemy potrzebne dane
	//myMainMap = myMapGui.getMainMap();
	

//	gui::IGUIFont* font2 = device->getGUIEnvironment()->getFont("../../media/fonthaettenschweiler.bmp");
	
	myKeyEventTimer = 0;
	myClickEventTimer = 0;
	
	clicked.x = 0;
	oldclicked.x = 0;
	
	// preloading
	std::vector <std::string> graphicList;
	// elementy mapy
	graphicList.push_back("data/gfx/map/castle.png");
	graphicList.push_back("data/gfx/map/legion_flag_blue.png");
	graphicList.push_back("data/gfx/map/legion_flag_green.png");
	graphicList.push_back("data/gfx/map/legion_flag_red.png");
	graphicList.push_back("data/gfx/map/legion_flag_yellow.png");
	graphicList.push_back("data/gfx/map/village.png");
	graphicList.push_back("data/gfx/map/world_map.jpg");
	
	// buttony
	graphicList.push_back("data/gfx/buttons/ok.png");
	graphicList.push_back("data/gfx/buttons/orders.png");
	
	// okna informacyjne
	graphicList.push_back("data/gfx/windows/city.png");
	graphicList.push_back("data/gfx/windows/legion.png");
	
	for (int counter = 0; counter < graphicList.size(); counter++) {
		video::ITexture* myImage;
		myImage = driver->getTexture(graphicList.at(counter).c_str());
		driver->makeColorKeyTexture(myImage, core::position2d<s32>(0,0));
	}
	//delete myImage;
}

void CGraphic::draw() {
	while (quit == false) {
		if (device->run()) {
			const u32 now = device->getTimer()->getTime();
			const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
			then = now;
			//std::cout << frameDeltaTime << std::endl;
			
			/*
			 * Tutaj jest obsługa czasów kliknięć
			 * zmniejszamy Event Timera jeśli jest większy niż 0 - po naciśnięciu klawisza lub kliknięciu myszą
			 */
			if (myKeyEventTimer > 0) 
				myKeyEventTimer -= frameDeltaTime;
				
			if (myClickEventTimer > 0)
				myClickEventTimer -= frameDeltaTime;
				
			//! obsluga  klawiszy
			if (myEventReceiver.getMouseState().LeftButtonDown) {
				SPoint click;
				click.x = myEventReceiver.getMouseState().Position.X;
				click.y = myEventReceiver.getMouseState().Position.Y;
				if (this->clickEvent())
					myMapGui->click(click.x, click.y); // idziemy do funkcji clickEvent
			}
			
			if (myEventReceiver.getMouseState().RightButtonDown) {
				clicked.x = myEventReceiver.getMouseState().Position.X - myEventReceiver.getMouseState().OldPosition.X;
				clicked.y = myEventReceiver.getMouseState().Position.Y - myEventReceiver.getMouseState().OldPosition.Y;
				
//				std::cout << myEventReceiver.getMouseState().Position.X - myEventReceiver.getMouseState().OldPosition.X << std::endl;
				myMapGui->moveMap(clicked.x, clicked.y);

			}
			/* 
			 * Escape? Wychodzimy?
			 */
			if (myEventReceiver.IsKeyDown(irr::KEY_ESCAPE)) {
				quit = true;
			}

				
			if (myEventReceiver.IsKeyDown(irr::KEY_LEFT))
				myMapGui->moveMap(irr::KEY_LEFT);
			else if (myEventReceiver.IsKeyDown(irr::KEY_RIGHT))
				myMapGui->moveMap(irr::KEY_RIGHT);
			
			if (myEventReceiver.IsKeyDown(irr::KEY_UP))
				myMapGui->moveMap(irr::KEY_UP);
			else if (myEventReceiver.IsKeyDown(irr::KEY_DOWN))
				myMapGui->moveMap(irr::KEY_DOWN);
				
			if (myEventReceiver.IsKeyDown(irr::KEY_SPACE)) {
				if (this->keypressedEvent())
					myMapGui->newDay();
			}
			
			//! Rysujemy scene
			driver->beginScene(true, true, SColor(255,100,101,140));
			myMapGui->drawAll(); //! ryssujemy mape
			driver->endScene(); 
		}
	}
}

int CGraphic::clickEvent() {
	if (myClickEventTimer <= 0) {
		myClickEventTimer = 0.5;
		return true;
	}
	return false;
}

int CGraphic::keypressedEvent() {
	if (myKeyEventTimer <= 0) {
		myKeyEventTimer = 1;
		return true;
	} else
		return false;
}

void CGraphic::animateLegionMove(SPoint from, SPoint to) {
    // animujemy przesuwanie sie legionu
    
}

void CGraphic::close() {
	device->drop();
}


int CGraphic::getKeyEvent() {

	return 0;
}

int CGraphic::getMouseEvent() {
	return 0;
}
