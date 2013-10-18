#include "CActor.h"

CActor::CActor() {
}
CActor::~CActor() {}

void CActor::createNewActor() {
    myStatus = ALIVE;
    myType = rand() % 7;
    std::cout << " - " << myType << std::endl;
    myName = Tools::createName();
    std::cout << " - " << myName << std::endl;
    myMorale = PEACE;

    CData dataloader;
    dataloader.openFile("datpl/actors.dat");
    // wczytujemy podstawowe wartosci dla atrybutow, pozniej dolosujemy reszte(?)

    // myType - rasa goscia
    std::cout << dataloader.s_search(myType, RACE) << std::endl; 
    myEnergy = dataloader.i_search(myType, ENERGY);
    myStrenght = dataloader.i_search(myType, STRENGTH);
    mySpeed = dataloader.i_search(myType, SPEED);
    myMagic = dataloader.i_search(myType, MAGIC);
    
    
    myCurrentEnergy = myEnergy; // dajemy zycia tyle ile jest maks;
    myCurrentMagic = myMagic;

    for (int counter=0; counter < 16; counter++) {
	mySpells[counter] = 0;
    }
}

void CActor::createNewMonster() {
    myType = rand() % 9 + 9;
    myName = Tools::createName();
}

void CActor::addEnergy(int energy) {
    myCurrentEnergy += energy;
    if (myCurrentEnergy > energy)
	myCurrentEnergy = energy;
}

void CActor::addMagic(int magic) {
    myCurrentMagic += magic;
    if (myCurrentMagic > magic)
	myCurrentMagic = magic;
}

void CActor::addItemToBackpack(CItem &item, int x, int y) {
//    myInventory.backpack[1][1] = item_id;
}

CItem CActor::getItemFromBackpack(int x, int y) {
//    return myInventory.backpack[1][1]; 
    return myInventory.backpack[x][y];
}

void CActor::addSpell(int spell_id) {
    mySpells[spell_id] = true;
}

void CActor::doHit(int how_much) {
    myCurrentEnergy -= how_much;
    if (myCurrentEnergy < 0)
	myStatus = DEAD;
}

std::string CActor::getRace() {
    CData *data = new CData();
    data->openFile("actors.dat");
//    return data->getName(myType);
}