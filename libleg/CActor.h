#ifndef __CACTOR_H_
#define __CACTOR_H_

#include "Tools.h"
#include "SInventory.h"
#include "CItem.h"
#include "SPoint.h"
#include "legcrypt/CData.h"

enum _morale {
    PEACE = 0,
    DEFENCE = 1,
    ATTACK = 2,
    PSYCHO = 3
};

enum _status {
    ALIVE = 0,
    DEAD = 1
};

enum _spells {
    POCISK = 0,
    PIGULA = 1,
    ODDECH_CHAOSU = 2,
    PLOMIENIE = 3,
    BLYSKAWICA = 4,
    INTUICJA = 5,
    LECZENIE = 6,
    UZDROWIENIE = 7,
    SWIATLOSC = 8,
    WSZECHWIEDZA = 9,
    GNIEW_BOZY = 10,
    SPOWOLNIENIE = 11,
    NAWROCENIE = 12,
    EKSPLOZJA = 13,
    NIEPEWNOSC = 14,
    USPOKOJENIE = 15,
};

class CActor {

    int myOwner; // wlasciciel aktora!
    int myStatus; // status aktora
    int myType; // typ (czlowiek, elf, itp)
    std::string myName; // imie
    int myMorale; // morale
    int myEnergy; // energia maksymalna
    int myCurrentEnergy; // energia aktualna
    int myStrenght; // sila
    int mySpeed; // szybkosc
    int myResistance; // odpornosc
    int myMagic; // magia maksymalna
    int myCurrentMagic; // magia aktualna
    int myExperience; // Doswiadczenie
    int myLoad; // obciazenie 
    SInventory myInventory; // aktualne wyposazenie 

    bool mySpells[16]; // lista czarow poznanych 0-nie zna 1-zna    
    SPoint myPosition; // pozycja
//    CData dataloader;
    
public:
    CActor();
    ~CActor();
    void createNewActor();
    void createNewMonster();

    int getType() const { return myType; }    
    std::string getName() const { return myName; }
    int getEnergy() const { return myEnergy; }
    int getCurrentEnergy() const { return myCurrentEnergy; }
    int getStrenght() const { return myStrenght; }
    int getSpeed() const { return mySpeed; } 
    int getOwner() const { return myOwner; }
    void setOwner(int owner) { myOwner = owner; }
    void addItemToBackpack(CItem &item, int x, int y); // dodajemy item do plecaka, teraz pytanie, kopiujemy czy odnosimy sie do juz stworzonego?
    CItem getItemFromBackpack(int x, int y); // pobieramy id przedmiotu
    void addSpell(int spell_id); // dodajemy czar do 'ksiegi'
    void addEnergy(int energy);
    void addMagic(int magic);
    
    void doHit(int how_much);
    
    // dane z plikow
    std::string getRace(); // pobieramy jaka rasa
};

#endif
