#include "CData.h"

CData::CData() {}
CData::~CData() {
    myFile.close();
}

void CData::openFile(std::string filename) {
    CLegCrypt crypt;
//    std::cout << "[CData] Opening file..." << std::endl;
    myFile.open(std::string("data/"+filename).c_str(), std::ios::in);
    if (!myFile.is_open()) 
	std::cout << "Nie udalo sie otworzyc data/" << filename << std::endl;

    while (!myFile.eof()) {
//	std::cout << "reading" << std::endl;
	std::string line;
	std::getline(myFile, line); // pobieramy aktualna linie
	std::string decodedline =  crypt.decode(line); // dekodujemy linie na normalny tekst
//	std::cout << "CData -> " <<  decodedline << std::endl;
	int counter = 0; std::string myword; 
	for (int i = 0; i < decodedline.length(); i++) { // sprawdzamy znak po znaku cala linie
	    if (decodedline[i] == '|' || decodedline[i] == '\n') { // mamy rozdzielacz
//		std::cout << "myWord " << myword << std::endl;
		myLine.push_back(myword); // wiec dodajemy odczytana wczesniej slowo do wektora linii
		myword.clear(); // czysciimy slowo
		counter++; // licznik
	    }
	    else
		myword += decodedline[i]; // zbieramy cale jedno slowo
	}
//	std::cout << "myLine -> " << myLine.size() << " " << myLine.at(0)  << std::endl;
	myData.push_back(myLine); // mamy uzbierany wektor calej linii dorzucamy do wektora myData
	myLine.clear(); // czyscimy stary wektor linii
    }
    
}


// privaate
std::string CData::s_search(int id, int column) {
//	std::cout << "s_search " << std::endl;
    return myData.at(id).at(column);
}

int CData::i_search(int id, int column) {
    // konwersja ze string do int
//	std::cout << "i_search - id " << id << " column: " << column << std::endl;
//	std::cout << "size: " << myData.at(id).size() << std::endl;
    std::stringstream ss;
    int value;
    ss << myData.at(id).at(column);
    ss >> value;
//    std::cout << value << std::endl;
    return value;
}
