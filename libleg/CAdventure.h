#ifndef __CADVENTURE_H_
#define __CADVENTURE_H_

#include "SPoint.h" 
#include <cstdlib>

enum _adventures {
    KOPALNIA = 0, // kopalnia zlota koboldow
    KURHAN = 1, 
    OBOZOWISKO = 2, // obozowisko bandytow 
    CORKA = 3, // po uwolnieniu corki, dostajemy miasto
    GORA = 4, // gora i jej szczerbiec!
    MAG = 5, // skoksowany mag, z dobrymi czarami
    GROTA = 6, // paladyn
    GROBOWIEC = 7, // pierwsza ksiega = czary konkretne
    ORKI = 8, // orki i ich swiatynia = skarby
    BARBARZYNCA = 9, // czlowieczek wykoksowany
    WATAHA = 10, // wataha jakiegos przyglupa = nagroda
    JASKINIA = 11, // jaskinia wiedzy = kupa expa
    CHAOS = 12, // Super Uber Wladca Chaosu i jego pacholki do wyklepania
};

class CAdventure {
    int myType;
    SPoint myPosition; // pozycja na mapie
public:
    CAdventure();
    ~CAdventure();
    
    void createAdventure();
};

#endif
