CC=g++
DEPS=write-read.h
OBJ=main.o strtk.o
STRTK_PATH=strtk

main.out: $(OBJ)
	$(CC) -o $@ $^

main.o: main.cpp
	$(CC) -c $^

strtk.o: strtk/strtk.cpp
	$(CC) -c $^
