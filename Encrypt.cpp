// CIS22B
// Lab2
// Cameron March
// Encrypt.cpp

#include "Encrypt.h"

// This function will encrypt our file
void encrypt(std::string input, std::string output)
{
	// Create input and output streams
	std::ifstream fileIn(input.c_str());
	std::ofstream fileOut(output.c_str());

	std::cout << "Encrypted File: " << std::endl;

	char c;

	// Iterate through input file, encrypt each char,
	// and write them to output file
	while (fileIn.get(c))
	{
		c += 11;
		std::cout << c;
		fileOut.put(c);
	}
	std::cout << "\n" << std::endl;

	// Close the files
	fileIn.close();
	fileOut.close();
}
