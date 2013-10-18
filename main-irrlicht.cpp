#include "libleg/libleg.h"
#include "lgfx/leggfx.h"

// tworzymy nowa mapke
CMainMap *MainMap;
CGraphic *myGraphic;

int main() {
    srand ( time(NULL) );
	myGraphic = new CGraphic();
	myGraphic->init(); //! inicjujemy graficzke
	myGraphic->draw();
	
	myGraphic->close();
	delete myGraphic;


    delete MainMap;
    return 0;
}

