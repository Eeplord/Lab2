// Encrypt.cpp

#include "Encrypt.h"

void encrypt(std::string input, std::string output)
{
	std::ifstream fileIn(input.c_str());
	std::ofstream fileOut(output.c_str());

	std::cout << "Encrypted File: " << std::endl;

	char c;
	while (fileIn.get(c))
	{
		c += 11;
		std::cout << c;
		fileOut.put(c);
	}
	std::cout << std::endl;

	fileIn.close();
	fileOut.close();
}
