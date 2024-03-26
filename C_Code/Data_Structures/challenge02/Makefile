# Author: Chandrika Satyavolu
# Email: jsatyav2@nd.edu
#
# This is the Makefile for PC02

# CC is for the gcc compiler for C
CC := gcc

# CFLAGS are the required compiler flags for the CSE 20312 course
CFLAGS := -O2 -g -std=c11 -Wall -Wextra -Wconversion -Wshadow -lm -Werror

# Compilation for the array-merge.c
# Command: make array-merge
array-merge: array-merge.o
	$(CC) $(CFLAGS) -o array-merge array-merge.o

array-merge.o: array-merge.c
	$(CC) $(CFLAGS) -c array-merge.c

test-memory-array-merge: array-merge
	valgrind --leak-check=full ./array-merge
	
execute-array-merge: array-merge
	./array-merge

# Compilation for the struct-array.c
# Command: make struct-array
struct-array: struct-array.o
	$(CC) $(CFLAGS) -o struct-array struct-array.o

struct-array.o: struct-array.c
	$(CC) $(CFLAGS) -c struct-array.c

test-memory-struct-array: struct-array
	valgrind --leak-check=full ./struct-array
	
execute-struct-array: struct-array
	./struct-array

# Compilation for the struct-search.c
# Command: make struct-search	
struct-search: struct-search.o
	$(CC) $(CFLAGS) -o struct-search struct-search.o

struct-search.o: struct-search.c
	$(CC) $(CFLAGS) -c struct-search.c

test-memory-struct-search: struct-search
	valgrind --leak-check=full ./struct-search
	
execute-struct-search: struct-search
	./struct-search

# Make all
all: array-merge struct-array struct-search

# Make clean
clean:
	rm -rf *.o *.swp array-merge struct-array struct-search

