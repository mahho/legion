#include <iostream>
#include <fstream>
#include "../libleg/legcrypt/CLegCrypt.h"

int main(int argc, char *argv[]) {
    std::fstream file;
    file.open ("data.dat", std::fstream::in | std::fstream::out | std::fstream::app);
    
    std::fstream filetoencode;
    filetoencode.open (argv[1], std::fstream::in);
    
    std::string line;
    CLegCrypt crypt;    
    while (!filetoencode.eof()) {
	getline(filetoencode, line);
	if (line.length() > 0) {
	    std::cout << line << std::endl;
	    file << crypt.encode(line);
	    file << '\n';
	}
    }
    

    filetoencode.close();
    
    /*
    if (argc > 1) {
	std::string tekst = argv[1];
	CLegCrypt crypt;
	for (int i = 1; i < argc; i++) {
	    file << crypt.encode(argv[i]);
	}
	file << std::endl;
	std::cout << std::endl;
//	std::string encoded = crypt.encode(tekst);
//	std::cout << encoded << std::endl;
    } else {
	std::cout << "Za malo parametrow! ./encode tekst" << std::endl;
    }
     */
     
    file.close();
    return 0;
}
