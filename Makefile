CC = g++
CFLAGS = -Wall
LDFLAGS = -lm

all : run

run : Main.o Check.o Encrypt.o Decrypt.o
	$(CC) $(CFLAGS) Decrypt.o Encrypt.o Check.o Main.o $(LDFLAGS) -o run

Decrypt.o : Decrypt.cpp Decrypt.h
	$(CC) $(CFLAGS) -c Decrypt.cpp

Encrypt.o : Encrypt.cpp Encrypt.h
	$(CC) $(CFLAGS) -c Encrypt.cpp

Check.o : Check.cpp Check.h
	$(CC) $(CFLAGS) -c Check.cpp

Main.o : Main.cpp Check.h Worker.h
	$(CC) $(CFLAGS) -c Main.cpp

clean:
	rm run Decrypt.o Encrypt.o Check.o Main.o
