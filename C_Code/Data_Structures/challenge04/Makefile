# Author: Chandrika Satyavolu
# Email: jsatyav2@nd.edu
#
# This is the Makefile for PC04

# CC is for the gcc compiler for C
CC := gcc

# CFLAGS are the required compiler flags for the CSE 20312 course
CFLAGS := -O2 -g -std=c11 -Wall -Wextra -Wconversion -Wshadow -lm -Werror

# Compilation for the binary-converter.c
# Command: make binary-converter
binary-converter: binary-converter.o
	$(CC) $(CFLAGS) -o binary-converter binary-converter.o

binary-converter.o: binary-converter.c
	$(CC) $(CFLAGS) -c binary-converter.c

test-memory-binary-converter: binary-converter
	valgrind --leak-check=full ./binary-converter
	
execute-binary-converter: binary-converter
	./binary-converter


# Compilation for the que-with-two-stacks.c
# Command: make que-with-two-stacks

que-with-two-stacks: que-with-two-stacks.o
	$(CC) $(CFLAGS) -o que-with-two-stacks que-with-two-stacks.o

que-with-two-stacks.o: que-with-two-stacks.c
	$(CC) $(CFLAGS) -c que-with-two-stacks.c

test-memory-que-with-two-stacks: que-with-two-stacks
	valgrind --leak-check=full ./que-with-two-stacks
	
execute-que-with-two-stacks: que-with-two-stacks
	./que-with-two-stacks


# Make all
all: binary-converter que-with-two-stacks

# Make clean
clean:
	rm -rf *.o *.swp binary-converter que-with-two-stacks

