CC = g++
CFLAGS = -Wall
LDFLAGS = -lm

all : run

run : Main.o Check.o 
	$(CC) $(CFLAGS) Check.o Main.o $(LDFLAGS) -o run

Check.o : Check.cpp Check.h
	$(CC) $(CFLAGS) -c Check.cpp

Main.o : Main.cpp Check.h Worker.h
	$(CC) $(CFLAGS) -c Main.cpp

clean:
	rm run Check.o Main.o
