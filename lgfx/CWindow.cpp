#include "CWindow.h"

/*
 * Funklcja konwertujaca
 */
 irr::core::stringw strToStringW(const char* str){
    int s = mbstowcs(0,str,0) + 1;
    wchar_t *tmp = new wchar_t[s];
        
    //std::cout << "mbstowcs: "  << mbstowcs(0,str,0) <<std::endl;
    
    int charsWritten = mbstowcs(tmp,str,s);
    tmp[charsWritten] = L'\0';
    
    irr::core::stringw ret(tmp);
    delete[] tmp;

    return ret;
}

/*
 * od klasy
 */
CWindow::CWindow(IVideoDriver* &driver, gui::IGUIFont* &font) {
	myDriver = driver;
	myFont = font;
	
	myOkButton.myTexture = myDriver->getTexture("data/gfx/buttons/ok.png");
	myDriver->makeColorKeyTexture(myOkButton.myTexture, core::position2d<s32>(0,0));
	
	myOrdersButton.myTexture = myDriver->getTexture("data/gfx/buttons/btn_orders.png");
	myDriver->makeColorKeyTexture(myOrdersButton.myTexture, core::position2d<s32>(0,0));
	
	myPosition.x = 361;
	myPosition.y = 283;
	myPosition.width = 302;
	myPosition.height = 202;
	
	// położenie buttona OK
	SPoint pos;
	pos.x = myPosition.x + 210;
	pos.y = myPosition.y + 164;
	pos.width = 83;
	pos.height = 31;
	myOkButton.setProperties(pos, button::OK);
	myOkButton.visible = true;
	
	pos.x = myPosition.x + 10;
	pos.y = myPosition.y + 164;
	pos.width = 83;
	pos.height = 31;
	myOrdersButton.setProperties(pos, button::ORDERS);
	myOrdersButton.visible = false;
}
CWindow::~CWindow() {}

void CWindow::create() {
}

/*
 * Okno informacyjne o legionie
 */
void CWindow::legionInfo(CLegion &legion) {
	this->myLegion = legion;
    // wyswietlamy informacje o legionie
	myImage = myDriver->getTexture("data/gfx/windows/legion.png");
    myDriver->makeColorKeyTexture(myImage, core::position2d<s32>(0,0));
	myName = myLegion.getName();
	myType = window::INFO;

	if (myLegion.getOwner() == 1) {
		myOrdersButton.visible = true;
	} else
		myOrdersButton.visible = false;
}
/*
 * Okno z rozkazami dla legionu
 */
void CWindow::legionOrders() {
	// wyswietlamy informacje o legionie
	myImage = myDriver->getTexture("data/gfx/buttons/legion_orders.png");
    myDriver->makeColorKeyTexture(myImage, core::position2d<s32>(0,0));
	myPosition.x = 461;
	myPosition.y = 283;
	core::dimension2d< u32 > mySize;
	mySize = myImage->getSize();
	myPosition.width = mySize.Width;
	myPosition.height = mySize.Height;
	myOrdersButton.visible = false;
	myOkButton.visible = false;
	myType = window::LEGION_ORDERS;
}

/*
 * Okno informacyjne dla miasta
 */
void CWindow::cityInfo(CCity &city) {
	this->myCity = city;
	myImage = myDriver->getTexture("data/gfx/windows/city.png");
    myDriver->makeColorKeyTexture(myImage, core::position2d<s32>(0,0));

	myName = myCity.getName();
	myType = window::INFO;
	
	std::cout << myName << std::endl;
	// położenie buttona rozkazy
	//SPoint pos;
	//std::cout << myCity.getOwner() << std::endl;
	if (myCity.getOwner() == 1) {
		myOkButton.visible = true;
	} else
		myOrdersButton.visible = false;
}
/* 
 * Okno z rozkazami dla miasta
 */
void CWindow::cityOrders(CCity &myCity) {
}

int CWindow::click(int x, int y) {
//	std::cout << "KLIK KLIK" << std::endl;
//std::cout << myOkButton.myPosition.x << " " << x << " " << std::endl;

	if (x > myOkButton.myPosition.x && x < myOkButton.myPosition.x + myOkButton.myPosition.width &&
		y > myOkButton.myPosition.y && y < myOkButton.myPosition.y + myOkButton.myPosition.height) {
		//std::cout << "KLIK KLIK" << std::endl;
		return button::OK;
	} else if (myOrdersButton.visible == true && x > myOrdersButton.myPosition.x && x < myOrdersButton.myPosition.x + myOrdersButton.myPosition.width &&
		y > myOrdersButton.myPosition.y && y < myOrdersButton.myPosition.y + myOrdersButton.myPosition.height) {
		// klikniete w rozkazy
		return button::ORDERS;
	} else 
		return false;
}

/*
 * Funkcja rysująca wybrany obraz (z dodatkami - buttony [OK, rozkazy, itp])
 */
void CWindow::draw() {
	myDriver->draw2DImage(myImage, core::position2d<s32>(myPosition.x, myPosition.y), core::rect<s32>(0,0,myPosition.width,myPosition.height), 0, video::SColor(255,255,255,255), true);
	if (myFont) {
		irr::core::stringw str;
		str = strToStringW(myName.c_str());
		myFont->draw(str, core::rect<s32>(myPosition.x+170,myPosition.y+25,myPosition.x+200,myPosition.y+150), video::SColor(255,255,255,255));
		
		// sprawdzamy czy mamy ustawione buttony
		if (myOkButton.visible == true) 
			myDriver->draw2DImage(myOkButton.myTexture, core::position2d<s32>(myOkButton.myPosition.x, myOkButton.myPosition.y), core::rect<s32>(0,0,83,31), 0, video::SColor(255,255,255,255), true);
		if (myOrdersButton.visible == true) // jeśli mamy ustawiona pozycję, to wiadomo że button musi być
			myDriver->draw2DImage(myOrdersButton.myTexture, core::position2d<s32>(myOrdersButton.myPosition.x, myOrdersButton.myPosition.y), core::rect<s32>(0,0,myOrdersButton.myPosition.width,myOrdersButton.myPosition.height), 0, video::SColor(255,255,255,255), true);
	}
}


