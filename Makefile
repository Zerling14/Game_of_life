all: bin/main

bin/main: build/src/main.o build/src/matrix.o build/src/cell.o build/src/field.o
	mkdir bin -p
	gcc -Wall -o bin/main build/src/main.o build/src/matrix.o build/src/cell.o build/src/field.o

build/src/main.o: src/main.c
	mkdir build -p
	mkdir build/src -p
	gcc -Wall -c -o build/src/main.o src/main.c

build/src/matrix.o: src/matrix.c
	mkdir build -p
	mkdir build/src -p
	gcc -Wall -c -o build/src/matrix.o src/matrix.c
	
build/src/cell.o: src/cell.c
	mkdir build -p
	mkdir build/src -p
	gcc -Wall -c -o build/src/cell.o src/cell.c

.PHONY: clean
clean:
	rm build/* -rf
	rm bin/* -rf