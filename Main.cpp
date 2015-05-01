// Main.cpp

#include <iostream>

#include "Check.h"

void writeCheck();

int main()
{
	bool quit = false;
	std::string commands = "[1] Write a Check";
	char input;

	while(!quit)
	{
		std::cout << commands << std::endl;
		std::cin >> input;

		switch(input)
		{
			case '1': std::cout << input << std::endl; break;
			default: quit = true; break;
		}	
	}

	return 0;
}
