CC = gcc 
CFLAGS = -g -O2 -Wall -Wextra -Wpedantic -Wconversion
RUN = ./bin/maintest

all: bin/maintest

bin/maintest: build/library.o build/maintest.o
	$(CC) $(CFLAGS) -o $@ $^
	mv maintest bin
	
build/library.o: src/library.c src/library.h
	$(CC) $(CFLAGS) -c $<
	mv library.o build

build/maintest.o: src/maintest.c src/library.h
	$(CC) $(CFLAGS) -c $<
	mv maintest.o build
	
run:
	$(RUN)
	
clean:
	rm -f bin/maintest build/library.o build/maintest.o