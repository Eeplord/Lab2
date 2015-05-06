// CIS22B
// Lab2
// Cameron March
// Worker.h

#ifndef WORKER_H
#define WORKER_H

#include <cstring>

// This structure will hold the data for our workers
typedef struct
{
	std::string name;		// Worker's name
	bool isHourly;			// Is the worker on an hourly
					// or salary pay?

	// Union structure to hold either salary
	// or hourly pay structure
	union
	{
		// Hourly pay
		struct
		{
			double rate;
			double hours;
		}hourly;

		// Salary pay
		struct
		{
			double salary;
			double bonus;
		}salary;
	}pay;
}Worker;

#endif
