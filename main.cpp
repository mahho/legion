#include "libleg/libleg.h"

// tworzymy nowa mapke
CMainMap *MainMap;

int main() {

    srand ( time(NULL) );
    
    // generating new main map
    MainMap = new CMainMap();
    MainMap -> generateNewMap();
    
    std::cout << "Pobieram legiony " << std::endl;
	for (int i = 0; i < MainMap->myLegions.size(); i++) {
	    std::cout << "Sila: " << MainMap->myLegions.at(i).getStrength() << std::endl;
	    std::cout << "Zarlo: " << MainMap->myLegions.at(i).getFood() << std::endl;
	}


    std::string tryb;
    do {

	std::cout << "Ilosc legionow na mapie: " << MainMap->myLegions.size() << std::endl;	
	
	std::cout << "Komenda: ";
	std::cin >> tryb;

	for (int counter = 0; counter < myEvents.size(); counter++) {
	    std::cout << "Wykonuje eventa" << std::endl;
	}
	myEvents.clear();
	
	std::cout << "Zarlo: " << MainMap->myLegions.at(0).getFood() << std::endl;
	// tymczasowe
	if (tryb == "ruch") {
	    std::cout << "Podaj wspolrzedne" << std::endl;
	    int x; int y;
	    std::cin >> x; std::cin >> y;
	    int days = MainMap->myLegions.at(0).goTo(x, y, MOVE_ORDER);
	    std::cout << "majide: " << MainMap->myLegions.at(0).myId << std::endl;
	    std::cout << "Dotrzemy tam za " << days << " dni." << std::endl;
	// tymczasowe
	} /* else if (tryb == "szybkiruch") {
	    std::cout << "Podaj wspolrzedne" << std::endl;
	    int x; int y;
	    std::cin >> x; std::cin >> y;
	    int days = myLegions.at(0).goTo(x, y, FAST_MOVE);
	    std::cout << "Dotrzemy tam za " << days << " dni." << std::endl;
	    myLegions.at(0).setOrder(FAST_MOVE);
 	// tymczasowe
 	}  else if (tryb == "poluj") {
	    std::cout << "Rozpoczynamy polowanie" << std::endl;
	    myLegions.at(0).setOrder(HUNT);
	}
	
	// tymczasowe
	else */
	
	// Nowy dzien...
	if (tryb == "tura") {
	    MainMap->newDay();
	}

    } while (tryb != "q");



    // delete objects
    delete MainMap;
    return 0;
}

