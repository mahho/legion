#include "CLegion.h"

CLegion::CLegion() {
    myPosition.x = rand() % 2000+10;
    myPosition.y = rand() % 1500+10;
    myPosition.width = 15;
    myPosition.height = 15;
    
//    myTargetPosition = myPosition;

    myOrder = CAMP_ORDER;
    myState = OK;
//    myName = Tools::createName();

    //this->goTo(rand() % 2048, rand() % 1536, MOVE_ORDER);
}
CLegion::~CLegion() {}

void CLegion::createLegion(int howManyActors) {
    std::cout << "[CLegion] createLegion" << std::endl;
    int overall_speed = 0;
    
    if (howManyActors > 10)
	howManyActors = 10;
    if (howManyActors > 0) {
	for (int counter = 0; counter < howManyActors; counter++) {
	    CActor newActor;
	    newActor.createNewActor();
	    newActor.setOwner(this->myOwner); // przypisujemy aktora do wlasciciela legionu
	    overall_speed += newActor.getSpeed();
	    myActors.push_back(newActor);
	    
	}
    }
    myFood = rand() % 50 + 50;
//    mySpeed = ((overall_speed/myActors.size())/5);
    this->calculateSpeed();
    std::cout << "[CLegion] " << mySpeed << std::endl;

}

std::vector<CActor> CLegion::getActors() {
    return myActors;
}

void CLegion::setOrder(int order) {
    myOrder = order;
    std::cout << "[CLegion] Nowy rozkaz: " << myOrder << std::endl;
}


int CLegion::goTo(int x, int y, int move_type) {
    myDestination.x = x;
    myDestination.y = y;
    std::cout << "[CLegion] Dane ruchu pozycja / cel " << myPosition.x << " " << myPosition.y << " " << x << " " << y << std::endl;
    std::cout << "[CLegion] myDestination " << myDestination.x << " " << myDestination.y << std::endl;

    SPoint d;
    d.x = myDestination.x - myPosition.x;
    d.y = myDestination.y - myPosition.y;
    std::cout << "[CLegion] d.x " << d.x << " d.y " << d.y << std::endl;
    
    int days_left;
    // co najmniej jedna delta jest rozna, wiec rozpoczynamy ruch
    if (d.x != 0 || d.y != 0) { 
	float dist = sqrt((d.x * d.x) + (d.y * d.y)) + 0.2;  // sprawdzamy odleglosc miedzy punktami
	if (move_type == MOVE_ORDER)
	    days_left = dist/mySpeed;
	else if (move_type == FAST_MOVE_ORDER)
	    days_left = dist/(mySpeed*2);
	    
		std::cout << "[CLegion] Pozostalo dni: " << days_left << std::endl;
		myOrder = MOVE_ORDER;
	//	std::cout << "[CLegion] Order: " << this->getOrder() << " " << myOrder << " majide: " << myId <<  std::endl;
		return days_left;
    } else
	return 0;
}

void CLegion::calculateSpeed() {
    int overall_speed = 0;
    for (int counter = 0; counter < myActors.size(); counter++) {
		overall_speed += myActors.at(counter).getSpeed();
    }
    mySpeed = ((overall_speed/myActors.size())/2);
    
    std::cout << "[CLegion] Caly speed: " << overall_speed << "; Speed po kalkulacji: " << mySpeed << std::endl;
}

void CLegion::newTurn() {
//    std::cout << "[CLegion] newTurn() " << std::endl;
    
    if (myFood/myActors.size() == 1)
        std::cout << "[CLegion] Zarcia na 1 dzien" << std::endl;
    else if (myFood <= 0) {
	// zarcie sie skonczyli
		std::cout << "[CLegion] Legion iz ded" << std::endl;
		myState = DISBANDED;
    }

//    std::cout << "Order: " << myOrder << " " << this->getOrder() << " majide: " << myId << std::endl;    
    if (this->getOrder() == CAMP_ORDER) {
		std::cout << "[CLegion] kampie..." << std::endl;
		doCamp();
    } else if (myOrder == MOVE_ORDER) {
		std::cout << "[CLegion] ide..." << std::endl;
		doMove();
    }
}

// prywatne funkcje
void CLegion::doCamp() {
    myFood -= myActors.size();
    for (int counter = 0; counter < myActors.size(); counter++) {
		myActors.at(counter).addMagic(rand() % 5 + 5);
		myActors.at(counter).addEnergy(rand() % 20 + 10);
    }
}


void CLegion::doMove() {
    int tmp_speed;
    if (myOrder == FAST_MOVE_ORDER) {
		tmp_speed = mySpeed * 2;
		myFood -= myActors.size()*2;
    }
    else {
		tmp_speed = mySpeed;
		myFood -= myActors.size();
    }
    
    SPoint d; // delta 
    SPoint v; // vector
    SPoint d_speed; // delta szybkosci
    
    myOldPosition = myPosition;  // ustawiamy pozycje jako stara
    
    // obliczamy delta x i delta y
    d.x = myDestination.x - myPosition.x;
    d.y = myDestination.y - myPosition.y;
    

    // co najmniej jedna delta jest rozna, wiec rozpoczynamy ruch
    if (d.x != 0 || d.y != 0) { 
	float dist = sqrt((d.x * d.x) + (d.y * d.y)) + 0.2;  // sprawdzamy odleglosc miedzy punktami
	int days = dist/tmp_speed;
	
	// wyliczamy predkosc legionu do celu
	float v_x = d.x / dist;
	float v_y = d.y / dist;
	
//	std::cout << v_x << " " << v_y << std::endl;
	
//	std::cout << "Dist: " << dist << " Days: " << days << " Speed: " << tmp_speed << std::endl;
	
	// nowa pozycja
	myPosition.x += v_x * tmp_speed;
	myPosition.y += v_y * tmp_speed;
	
	if (d.x < 0)
	    d.x = d.x * -1;
	if (d.y < 0)
	    d.y = d.y * -1;
	
	if (d.x < tmp_speed)
	    myPosition.x = myDestination.x;
	if (d.y < tmp_speed)
	    myPosition.y = myDestination.y;

	if (myPosition.x == myDestination.x && myPosition.y == myDestination.y)
	    this->setOrder(CAMP_ORDER);
	else 
	    this->setOrder(MOVE_ORDER);
	
//	setOrder(CAMP_ORDER); // kampimy, doszlismy do celu
    } else
	std::cout << "Poz: " << myPosition.x << " " << myPosition.y << std::endl;
}


int CLegion::getStrength() { 
    int str = 0;
    for (int counter = 0; counter < myActors.size(); counter++) {
	str += myActors.at(counter).getStrenght();
    }
    return str;
}


void CLegion::setTarget(SPoint target) {
    myDestination = target;
    std::cout << "Nowy cel: " << target.x << " " << target.y << std::endl;
    this->setOrder(MOVE_ORDER);
}

bool CLegion::doAttack() {
}
