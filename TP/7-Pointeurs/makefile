CC=gcc
CFLAGS=-Wall -std=c99 -lm -g -Wno-deprecated
OBJ=listeC.o main.o

liste: $(OBJ)
	$(CC) -o Liste $(OBJ) $(CFLAGS)

glut.o: listeC.h listeC.c
	$(CC) -c listeC.c -o listeC.o $(CFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o
	rm -f Liste