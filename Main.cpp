// Main.cpp

#include <iostream>
#include <cstring>

#include "Check.h"
#include "Encrypt.h"
#include "Decrypt.h"
#include "Worker.h"

void writeCheck();
void payWorker();

int main()
{
	bool quit = false;
	std::string commands = "[1] Write a Check\n[2] Hourly/Salary Workers\n[3] Encrypt File\n[4] Decrypt File\n[q] Quit";
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

			case '2':
				payWorker();
				break;

			case '3':
				encrypt("JuliusCaesar.txt", "JuliusCaesarEncrypted.txt");
				break;	

			case '4':
				decrypt("JuliusCaesarEncrypted.txt", "JuliusCaesarDecrypted.txt");
				break;

			default: 
				quit = true;
				break;
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

void payWorker()
{
	Worker worker;

	std::cout << "Enter your worker's name: " << std::endl;
	std::cin >> worker.name;
	
	char input;
	bool loop = true;

	while (loop)
	{
		std::cout << "Is your worker hourly or salaried (h/s): " << std::endl;
		std::cin >> input;
		switch (input)
		{
			case 'h':
				worker.isHourly = true;
				loop = false;
				break;

			case 's':
				worker.isHourly = false;
				loop = false;
				break;
			
			default:
				std::cout << "Only 'h' or 's' is accepted!" << std::endl;
				break;
		}
	}

	if (worker.isHourly)
	{
		double amount;
		loop = true;
		while (loop)
		{
			std::cout << "Enter hourly rate: " << std::endl;
			std::cin >> amount;

			if (amount < 0)
			{
				std::cout << "Hourly rate cannot be negative!" <<
					std::endl;
			}
			else
			{
				worker.pay.hourly.rate = amount;
				loop = false;
			}
		}
		
		loop = true;
		while (loop)
		{
			std::cout << "Enter hours worked: " << std::endl;
			std::cin >> amount;

			if (amount > 80)
			{
				std::cout << "Workers cannot get paid" <<
				       	" for more than 80 hours!" << std::endl;
			}
			else if (amount < 0)
			{
				std::cout << "Workers cannot work negative" <<
					" hours!" << std::endl;
			}
			else
			{
				worker.pay.hourly.hours = amount;
				loop = false;
			}
		}

		std::cout << worker.name << " should be paid $" <<
			(worker.pay.hourly.rate * worker.pay.hourly.hours) <<
			std::endl;
	}
	else
	{
		double amount;
		loop = true;
		while (loop)
		{
			std::cout << "Enter their salary: " << std::endl;
			std::cin >> amount;

			if (amount < 0)
			{
				std::cout << "Salary cannot be negative!" <<
					std::endl;
			}
			else
			{
				worker.pay.salary.salary = amount;
				loop = false;
			}
		}

		loop = true;
		while (loop)
		{
			std::cout << "Enter their bonus: " << std::endl;
			std::cin >> amount;

			if (amount < 0)
			{
				std::cout << "Bonus cannot be negative!" <<
					std::endl;
			}
			else
			{
				worker.pay.salary.bonus = amount;
				loop = false;
			}
		}

		std::cout << worker.name << " should be paid $" <<
			(worker.pay.salary.salary + worker.pay.salary.bonus) <<
			std::endl;
	}
}
