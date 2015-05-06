// CIS22B
// Lab2
// Cameron March
// Check.h

#ifndef CHECK_H
#define CHECK_H

#include <iostream>
#include <cstring>
#include <cmath>

// Check class will store all data we need
class Check
{
	public:
		// Constructor
		Check(std::string name, double amount, int day,
			int month, int year);

		// Overriding the << operator for easy printing
		friend std::ostream& operator<<(std::ostream& out,
			Check const& check);

	private:
		std::string name_;	// Name of person writing check
		double amount_;		// Amount in dollars
		int day_;		// Day check was written
		int month_;		// Month "             "
		int year_;		// Year "              "
};

#endif
