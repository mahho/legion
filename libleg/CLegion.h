#ifndef __CLEGION_H_
#define __CLEGION_H_

#include "CActor.h"
#include "SPoint.h"
#include "CSimulatedAction.h"
#include <vector>
#include <cstdlib>
#include <string>
#include <cmath>

enum _state {
    OK = 0,
    DISBANDED = 1,
};

enum _orders {
    CAMP_ORDER = 0,
    MOVE_ORDER = 1,
    FAST_MOVE_ORDER = 2,
    HUNT_ORDER = 3,
};


class CLegion {

    std::vector <CActor> myActors; // lista aktorow na legion
    
    int myState; // status legionu
    int myAction; // aktualna akcja
    
    SPoint myPosition; // pozycja (x,y)
    SPoint myOldPosition; // stara pozycja
    SPoint myDestination; // pozycja docelowa ruchu
    SPoint myTargetPosition; // pozycja celu
    SPoint myOldTargetPosition; // stara pozycja celu
        
    std::string myName; // nazwa legionu
    int myOwner; // id wlasciciela legionu
    int myOrder; // rozkaz
    int mySpeed; // szybkosc legionu
    int myFood; // ilosc zarcia legionu

// prywatne funkcje
    void doCamp(); // kampowanie
    void doMove(); // ruch legionu
    
    /*
     * Zmienne dla grafiki
     */
    bool myInfoOpened; // info
public:
    CLegion();
    ~CLegion();
    int myId;
    void createLegion(int howManyActors);
    std::vector <CActor> getActors();
    std::string getName() const { return myName; }
    int getState() const { return myState; }
    int getOwner() const { return myOwner; }
    void setOwner(int newOwner)  { myOwner = newOwner; }
    SPoint getPosition() const { return myPosition; }
    SPoint getOldPosition() const { return myOldPosition; }
    int getFood() const { return myFood; }
    void addFood(int how_much) { myFood += how_much; }
    int getDaysOfFood() const { return myFood/myActors.size(); }
    void setOrder(int order);
    int goTo(int x, int y, int move_type);
    void calculateSpeed();
    void newTurn(); // nowa tura
    void setTarget(SPoint target);
    bool doAttack(); // no to doszlismy do ataku (1) lub jeszcze idziemy (0)
    
    // 
    int getStrength(); // wylicza sile legionu    
    // 
    int getOrder() { return myOrder; }
    
    /*
     * Zmienne dla grafiki
     */
     void setInfo(bool state) { myInfoOpened = state; }
     bool getInfo() const { return myInfoOpened; }
};

#endif
