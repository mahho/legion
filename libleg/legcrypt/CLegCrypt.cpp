#include "CLegCrypt.h"

CLegCrypt::CLegCrypt() {
	/*
	* KLUCZE SZYFRUJACE
	*
	*/
	std::string _supertajnyklucz = "superTajnyDlugiMegaKlucz\"!@$%^&junoluotajminitakdalej!@#$%&*()_+{}:>?><";
//	std::cout << supertajnyklucz.length() << std::endl;
	
	supertajnyklucz = _supertajnyklucz;
}
CLegCrypt::~CLegCrypt() {}

std::string CLegCrypt::encode(std::string text) {
	std::string encoded;
	for (int i = 0; i < text.length(); i++) {
		// nie chcemy zeby trafil nam sie znak < 32
		int tmpencoded;
		int random;
		do {
			random = rand() % supertajnyklucz.length();
			tmpencoded = (int)text[i] ^ (int)supertajnyklucz[random];
//			std::cout << "TMPEncoded: " << tmpencoded;
		} while ( tmpencoded < 32 && tmpencoded > 0);
		encoded += (char) tmpencoded;
		encoded += (char)(random+32);
		
//		std::cout << "Koduje: " << (int)text[i] << " ^ " << (int)supertajnyklucz[random] << " = " << int((int)text[i] ^ (int)supertajnyklucz[random]) << std::endl;
	}
	return encoded;
//    return encoded;
}


std::string CLegCrypt::decode(std::string text) {
	std::string decoded;
//	std::cout << text << std::endl;
	for (int i = 0; i < text.length(); i+=2) {
//		std::cout << "Dekoduje: " << (int)text[i] << " ^ " << (int)supertajnyklucz[(int)text[i+1]] << " = " << int((int)text[i] ^ (int)supertajnyklucz[(int)text[i+1]]) <<std::endl;
		if (text[i] != '\n') {
			decoded += char((int)text[i] ^ (int)supertajnyklucz[(int)text[i+1]-32]);
//			std::cout << char((int)supertajnyklucz[(int)text[i+1]-33]);
		}
		else 
		    break;
	}
//	std::cout << "Decoded: " << decoded << std::endl;
	return decoded;
}

