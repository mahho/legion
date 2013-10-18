#ifndef __CPLAYERPATTERN_H_
#define __CPLAYERPATTERN_H_

#include "CLegion.h"
#include "CCity.h"

class CPlayerPattern {
protected:
    std::string myName; // nazwa gracza
    int myTreasure; // ilosc skarbu
    int myState; // status
    int myId;
    
public:
    CPlayerPattern();
    virtual ~CPlayerPattern();
    virtual std::string getName() { return myName; }
    virtual int getId() { return myId; }
    virtual int getTreasure() { return myTreasure; }
    virtual void addTreasure(int howmuch) { myTreasure += howmuch; } // dodajemy odpowiednia ilosc kasy na konto
};

#endif
 