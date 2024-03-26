# Author: Chandrika Satyavolu
# Email: jsatyav2@nd.edu
#
# This is the Makefile for Code Environment Setup Example

# CC is for the gcc compiler for C
CC := gcc

# CFLAGS are the required compiler flags for the CSE 20133 course
CFLAGS := -O2 -g -std=c11 -Wall -Wextra -Wconversion -Wshadow -lm -Werror
# Compilation for the nothing program
o Command: make nothing

array-rotation: array-rotation.o
	$(CC) $(CFLAGS) -o array-rotation array-rotation.o

array-rotation.o: array-rotation.c
	$(CC) $(CFLAGS) -c array-rotation.c

# Make all
#all: nothing hello specifiers helloSpec

# Make clean
clean:
	rm -rf *.o *.swp array-rotation
