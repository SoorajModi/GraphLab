CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

all: Graph.h
	$(CC) $(CFLAGS) Graph.c -o graph
	./graph
	valgrind ./graph

clean:
	rm *.o graph
