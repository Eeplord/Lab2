// Worker.h

#ifndef WORKER_H
#define WORKER_H

#include <cstring>

typedef struct
{
	std::string name;
	bool isHourly;
	union
	{
		struct
		{
			double rate;
			double hours;
		}hourly;

		struct
		{
			double salary;
			double bonus;
		}salary;
	}pay;
}Worker;

#endif
