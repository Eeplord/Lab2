// CIS22B
// Lab2
// Cameron March
// Decrypt.cpp

#include "Decrypt.h"

// Function that will decrypt our file
void decrypt(std::string input, std::string output)
{
	// Create an input and output stream
	std::ifstream fileIn(input.c_str());
	std::ofstream fileOut(output.c_str());

	std::cout << "Decrypted File: " << std::endl;

	char c;

	// Iterate through input file, decrypt each char,
	// and write it to output file
	while (fileIn.get(c))
	{
		c -= 11;
		std::cout << c;
		fileOut.put(c);
	}
	std::cout << std::endl;

	// Close the files
	fileIn.close();
	fileOut.close();
}
