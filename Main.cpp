// Main.cpp

#include <iostream>
#include <cstring>

#include "Check.h"

void writeCheck();

int main()
{
	bool quit = false;
	std::string commands = "[1] Write a Check\n[q] Quit";
	char input;

	while(!quit)
	{
		std::cout << commands << std::endl;
		std::cin >> input;

		switch(input)
		{
			case '1':
				writeCheck();
				break;

			default: quit = true; break;
		}	
	}

	return 0;
}

void writeCheck() 
{
	std::string name;
	int day, month, year;
	double amount;

	std::cout << "Enter your name: ";
	std::getline(std::cin, name);
	std::getline(std::cin, name);

	std::cout << "Enter the day (##): ";
	std::cin >> day;

	std::cout << "Enter the month (##): ";
	std::cin >> month;

	std::cout << "Enter the year (####): ";
	std::cin >> year;

	std::cout << "Enter amount: ";
	std::cin >> amount;

	if(amount < 0)
	{
		std::cout << "Amount must be positive!" << std::endl;
	}
	else if(amount > 10000)
	{
		std::cout << "Amount must be less than $10,000!" << std::endl;
	}
	else if(amount == 0)
	{
		std::cout << "Cannot write a check for $0!" << std::endl;
	}
	else
	{
		Check check(name, amount, day, month, year);
		std::cout << check << std::endl;
	}

}
