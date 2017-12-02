[![Build Status](https://travis-ci.org/Zerling14/Game_of_life.svg?branch=master)](https://travis-ci.org/Zerling14/Game_of_life)

# Conway's Game of Life with simple rules in terminal

 How compile?
```
$ make
```
How run?
```
$ bin/main
```

All the commands, that you can use:

```
help: displays help.

next: repeats the previous command.

write [file_name]: writes the matrix to a file (you must specify a file name).

read [file_name]: reads the file containing the matrix and its settings (you must specify a file name)

loop [repeat_num] [delay]: repeats "calc" and "print", "repeat_num" times and with a "delay" in sec, delay is maybe float, repeat_num can be zero then the loop will be infinite.

calc: makes one game step.

print: print matrix in console.

step: makes one game step and print matrix in console.

clear: clear console.

exit: completes the game.
```
