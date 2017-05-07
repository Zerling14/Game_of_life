all: bin/main

bin/main: build/src/main.o build/src/matrix.o
	mkdir bin -p
	gcc -Wall -o bin/main build/src/main.o build/src/matrix.o

build/src/main.o:
	mkdir build -p
	mkdir build/src -p
	gcc -Wall -c -o build/src/main.o src/main.c

build/src/matrix.o:
	mkdir build -p
	mkdir build/src -p
	gcc -Wall -c -o build/src/matrix.o src/matrix.c

.PHONY: clean
clean:
	rm build/* -rf
	rm bin/* -rf