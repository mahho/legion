#include <iostream>
#include <fstream>
#include "../libleg/legcrypt/CLegCrypt.h"

int main(int argc, char *argv[]) {
    std::fstream file;
    file.open ("data.dat", std::fstream::in | std::fstream::out | std::fstream::app);
    std::string line;
    CLegCrypt crypt;
    std::string decoded;
    while (!file.eof()) {
	getline(file, line);
	decoded += crypt.decode(line);
	std::cout << crypt.decode(line) << std::endl;
    }
    std::cout << decoded << std::endl;
    
    /*
    if (argc > 1) {
	std::string tekst = argv[1];

	std::string decoded = crypt.decode(tekst);
	std::cout << decoded << std::endl;
//	std::cout << crypt.decode("c-12@x12ł*fgZs)zzsa2*12as@x))");
    } else {
	std::cout << "Za malo parametrow! ./encode tekst" << std::endl;
    } */
    
    return 0;
}
