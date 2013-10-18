#ifndef __CDATA_H_
#define __CDATA_H_

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "CLegCrypt.h"

enum _atributes {
    RACE = 1,
    ENERGY = 2,
    STRENGTH = 3,
    SPEED = 4,
    MAGIC = 5
};

class CData {
    std::fstream myFile;
    std::vector< std::vector < std::string > > myData;
    std::vector < std::string > myLine;
            
    
public:
    CData();
    ~CData();
    void openFile(std::string filename);
    std::string s_search(int id, int column);
    int i_search(int id, int column);

};

#endif
