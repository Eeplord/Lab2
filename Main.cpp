// CIS22B
// Lab2 
// Cameron March
// Main.cpp

#include <iostream>
#include <cstring>

// Importing all our custom classes
#include "Check.h"
#include "Encrypt.h"
#include "Decrypt.h"
#include "Worker.h"

// Function prototypes
void writeCheck();
void payWorker();

int main()
{
	bool quit = false;
	std::string commands = "[1] Write a Check\n[2] Hourly/Salary Workers\n[3] Encrypt File\n[4] Decrypt File\n[q] Quit";
	char input;

	// Menu Loop
	while(!quit)
	{
		std::cout << commands << std::endl;
		std::cin >> input;

		// Determining what the user wants to do
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

// Handles the writing of a check using the Check class
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

	// Loop to handle invalid entries of amount of money
	bool loop = true;
	while (loop)
	{
		std::cout << "Enter amount: ";
		std::cin >> amount;
	
		// Negative amounts not allowed	
		if(amount < 0)
		{
			std::cout << "Amount must be positive!" << std::endl;
		}
		// Amounts greater than 10,000 not allowed
		else if(amount > 10000)
		{
			std::cout << "Amount must be less than $10,000!" << std::endl;
		}
		// Doesn't make sense to write a check for 0	
		else if(amount == 0)
		{
			std::cout << "Cannot write a check for $0!" << std::endl;
		}
		else
		{
			loop = false;
		}
	}
	// Use the checks overwritten method to display itself
	Check check(name, amount, day, month, year);
	std::cout << check << std::endl;
}

// Handles creating workers and determining how much they should be paid
void payWorker()
{
	Worker worker;

	std::cout << "Enter your worker's name: ";
	std::getline(std::cin, worker.name);
	std::getline(std::cin, worker.name);
	
	char input;
	bool loop = true;

	// This loop makes sure the user tells us if the worker
	// is salaried or hourly
	while (loop)
	{
		std::cout << "Is your worker hourly or salaried (h/s): ";
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

	// Handling for an hourly worker
	if (worker.isHourly)
	{
		double amount;
		loop = true;

		// This loop ensures we get a valid value for
		// hourly pay rate
		while (loop)
		{
			std::cout << "Enter hourly rate: ";
			std::cin >> amount;

			// Nobody should get paid a negative amount
			if (amount < 0)
			{
				std::cout << "Hourly rate cannot be negative!" << std::endl;
			}
			else
			{
				worker.pay.hourly.rate = amount;
				loop = false;
			}
		}
	
		// This loop makes sure that hours are not negative
		// or over 80	
		loop = true;
		while (loop)
		{
			std::cout << "Enter hours worked: ";
			std::cin >> amount;

			// We don't want to pay our workers overtime
			if (amount > 80)
			{
				std::cout << "Workers cannot get paid" <<
				       	" for more than 80 hours!" << std::endl;
			}
			// Don't accept a negative number
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
		// Calculate how much they should be paid and display it
		std::cout << worker.name << " should be paid $" <<
			(worker.pay.hourly.rate * worker.pay.hourly.hours) <<
			"\n" << std::endl;
	}
	// This section handles salaried workers
	else
	{
		double amount;
		loop = true;

		// Make sure their salaries are valid
		while (loop)
		{
			std::cout << "Enter their salary: ";
			std::cin >> amount;

			// We won't accept a negative salary
			if (amount < 0)
			{
				std::cout << "Salary cannot be negative!" << std::endl;
			}
			else
			{
				worker.pay.salary.salary = amount;
				loop = false;
			}
		}

		// This loop makes sure their bonus is valid
		loop = true;
		while (loop)
		{
			std::cout << "Enter their bonus: ";
			std::cin >> amount;

			// No negative bonuses
			if (amount < 0)
			{
				std::cout << "Bonus cannot be negative!" << std::endl;
			}
			else
			{
				worker.pay.salary.bonus = amount;
				loop = false;
			}
		}

		// Calculate their pay and display it to the screen
		std::cout << worker.name << " should be paid $" <<
			(worker.pay.salary.salary + worker.pay.salary.bonus) <<
			"\n" << std::endl;
	}
}
