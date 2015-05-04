// Check.cpp

#include "Check.h"

std::string convertIntToString(int digit);

Check::Check(std::string name, double amount, int day, int month, int year)
{
	name_ = name;
	amount_ = amount;
	day_ = day;
	month_ = month;
	year_ = year;
}

std::ostream& operator<<(std::ostream& out, Check const& check)
{
	out << "\t\t\t\t\t\t\t\t\tDate " << check.month_ << "\\" << check.day_ <<
		"\\" << check.year_ <<	std::endl;

	out << "Pay to the order of " << check.name_ << std::endl;

	int dollars, cents;
	dollars = floor(check.amount_);
	cents = check.amount_ * 100 - dollars * 100;

	out << "\t\t\t\t\t\t\t\t\t$" << dollars << ".";

	if(cents < 10)
	{
		out << "0";
	}

	out << cents << std::endl;

	int thousands, hundreds, tens;
	tens      = dollars % 100;
	hundreds  = ((dollars % 1000) - tens) / 100;
	thousands = (dollars - hundreds - tens) / 1000;

	if(thousands != 0)
	{
		out << convertIntToString(thousands) << " Thousand ";
	}

	if(hundreds != 0)
	{
		out << convertIntToString(hundreds) << " Hundred ";
	}

	if(tens != 0)
	{
		out << convertIntToString(tens) << " ";
	}

	if((thousands + hundreds + tens) != 0)
	{
		out << "Dollars and ";
	}	

	out <<  cents << " Cents";

	out << std::endl;

	return out;
}

std::string convertIntToString(int digit)
{
	std::string message = "";

	if(digit >= 10 && digit < 20)
	{
		switch(digit)
		{
			case 10: message = "Ten"; break;
			case 11: message = "Eleven"; break;
			case 12: message = "Twelve"; break;
			case 13: message = "Thirteen"; break;
			case 14: message = "Fourteen"; break;
			case 15: message = "Fifteen"; break;
			case 16: message = "Sixteen"; break;
			case 17: message = "Seventeen"; break;
			case 18: message = "Eighteen"; break;
			case 19: message = "Nineteen"; break;
		}
	}
	else if(digit >= 20)
	{
		int ones = digit % 10;
		int tens = (digit - ones) / 10;

		switch(tens)
		{
			case 2: message = "Twenty"; break;
			case 3: message = "Thirty"; break;
			case 4: message = "Fourty"; break;
			case 5: message = "Fifty"; break;
			case 6: message = "Sixty"; break;
			case 7: message = "Seventy"; break;
			case 8: message = "Eighty"; break;
			case 9: message = "Ninety"; break;
		}
		
		if(ones != 0)
		{
			message += "-";
		}

		digit = ones;
	}

	switch(digit)
	{
		case 1: message += "One"; break;
		case 2: message += "Two"; break; 
		case 3: message += "Three"; break;
		case 4: message += "Four"; break;
		case 5: message += "Five"; break;
		case 6: message += "Six"; break;
		case 7: message += "Seven"; break;
		case 8: message += "Eight"; break;
		case 9: message += "Nine"; break;
	}

	return message;
}
