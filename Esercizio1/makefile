
CC = gcc 
CFLAGS = -g -O2 -Wall -Wextra -Wpedantic -Wconversion

maintest: maintest.c library.o
	${CC} ${CFLAGS} maintest.c library.o -o maintest

library.o: library.c
	${CC} ${CFLAGS} library.c -c