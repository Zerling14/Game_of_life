BIN=bin
BUILD=build
BUILD_SRC=build/src
BUILD_TEST=build/test

all: checkdir bin/main 

bin/main: build/src/main.o build/src/matrix.o build/src/cell.o
	gcc -Wall -o bin/main build/src/main.o build/src/matrix.o build/src/cell.o

build/src/main.o: src/main.c
	gcc -Wall -c -o build/src/main.o src/main.c

build/src/matrix.o: src/matrix.c
	gcc -Wall -c -o build/src/matrix.o src/matrix.c
	
build/src/cell.o: src/cell.c
	gcc -Wall -c -o build/src/cell.o src/cell.c

.PHONY: clean checkdir

checkdir:
	@if [ ! -d $(BIN) ] ; then mkdir bin ; fi
	@if [ ! -d $(BUILD) ] ; then mkdir build ; fi
	@if [ ! -d $(BUILD_SRC) ] ; then mkdir build/src ; fi
	@if [ ! -d $(BUILD_TEST) ] ; then mkdir build/test ; fi

clean: 
	rm -rf build
	rm -rf bin