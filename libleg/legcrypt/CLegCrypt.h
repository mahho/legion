#ifndef __CLEGCRYPT_H_
#define __CLEGCRYPT_H_

#include <iostream>
#include <string>
#include <cstdlib>

class CLegCrypt {
	std::string supertajnyklucz;
	
public:
	CLegCrypt();
	~CLegCrypt();

	// encoding
	std::string encode(std::string text);

	// decoding
	std::string decode(std::string text);
};

#endif
