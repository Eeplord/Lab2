// Worker.h

#ifndef WORKER_H
#define WORKER_H

#include <cstring>

typedef struct
{
	int val1;
	int val2;
} DataElement;

typedef union
{
	DataElement de;
	int val[2];
} Worker;

#endif
