// Check.h

#ifndef CHECK_H
#define CHECK_H

#include <iostream>
#include <cstring>
#include <math.h>

class Check
{
	public:
		Check(std::string name, double amount, int day,
			int month, int year);

		friend std::ostream& operator<<(std::ostream& out,
			Check const& check);

	private:
		std::string name_;
		double amount_;
		int day_;
		int month_;
		int year_;
};

#endif
