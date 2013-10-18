#ifndef __CITEM_H_
#define __CITEM_H_

#include <string>
#include <iostream>

enum _item_types {
    SWORD = 0,	// miecz
    AXE,	// topor
    SHIELD,	// tarcza
    BOW,	// luk
    ARROWS,	// strzaly
    ARMOR,	// zbroja
    HELMET,	// helm
    BOOTS,	// buty
    JAVELIN,	// oszczep
    CLUB,	// maczuga
    HAMMER,	// mlot
    SPELL,	// czar
    HERBS,	// ziola
    JEWELERY,	// kosztownosci
    CATAPULT,	// katapulta
    STONE,	// glaz
    FOOD,	// zywnosc
    MIXTURE,	// mikstura
    LEATHER,	// skora
};

class CItem {
    int myType; // typ przedmiotu
    std::string myName; // nazwa przedmiotu
    int myAttack; // wartosc ataku
    int myDefense; // wartosc obrony 

public:
    CItem();
    ~CItem();
    void createItem(); // tworzymy przedmiot (np do sklepow)
    void loadData(); // wczytujemy informacje z pliku o przedmiocie
    int getType() const { return myType; }
    std::string getName() const { return myName; }
    int getAttack() const { return myAttack; }
    int getDefense() const { return myDefense; }
};

#endif
