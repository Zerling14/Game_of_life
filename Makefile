all: bin/main

bin/main: build/src/main.o build/src/matrix.o build/src/cell.o
	mkdir bin -p
	gcc -Wall -o bin/main build/src/main.o build/src/matrix.o build/src/cell.o

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

bin/test: build/tests/main.o build/tests/matrix_test.o build/tests/cell_test.o build/src/cell.o build/src/matrix.o
	mkdir bin -p
	gcc -std=c99 -Wall -Werror build/src/matrix.o build/src/cell.o build/tests/main.o build/tests/matrix_test.o build/tests/cell_test.o -o bin/test
	bin/test

build/tests/cell_test.o: tests/cell_test.c
	mkdir build -p
	mkdir build/tests -p
	gcc -std=c99 -Wall -Werror -I src -I thirdparty -c tests/cell_test.c -o build/tests/cell_test.o

build/tests/matrix_test.o: tests/matrix_test.c
	mkdir build -p
	mkdir build/tests -p
	gcc -std=c99 -Wall -Werror -I src -I thirdparty -c tests/matrix_test.c -o build/tests/matrix_test.o

build/tests/main.o: tests/main.c
	mkdir build -p
	mkdir build/tests -p
	gcc -std=c99 -Wall -Werror -I thirdparty -c tests/main.c -o build/tests/main.o

.PHONY: clean

test: bin/test

clean: 
	rm -rf build
	rm -rf bin