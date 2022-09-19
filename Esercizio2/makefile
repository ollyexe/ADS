CC = gcc 
CFLAGS = -g -O3 -Wall -Wextra -Wpedantic -Wconversion
RUN = ./bin/maintest
TST = ./bin/unitytest

all: bin/maintest 

bin/unitytest: build/library.o build/unitytest.o
	$(CC) $(CFLAGS) -o $@ $^

bin/maintest: build/library.o build/maintest.o
	$(CC) $(CFLAGS) -o $@ $^
	
	
build/library.o: src/library.c src/library.h
	$(CC) $(CFLAGS) -c $<
	mv library.o build

build/maintest.o: src/maintest.c src/library.h
	$(CC) $(CFLAGS) -c $<
	mv maintest.o build

build/unitytest.o: src/unitytest.c src/library.h
	$(CC) $(CFLAGS) -c $<
	mv unitytest.o build

run:
	$(RUN) dictionary.txt correctme.txt

test:
	$(TST) 
	
clean:
	rm -f bin/maintest build/library.o build/maintest.o build/unitytest.o bin/unitytest

val:
	valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log bin/maintest records.csv