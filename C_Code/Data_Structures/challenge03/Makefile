# Author: Chandrika Satyavolu
# Email: jsatyav2@nd.edu
#
# This is the Makefile for PC03

# CC is for the gcc compiler for C
CC := gcc

# CFLAGS are the required compiler flags for the CSE 20312 course
CFLAGS := -O2 -g -std=c11 -Wall -Wextra -Wconversion -Wshadow -lm -Werror

# Compilation for the dll-ordered-list.c
# Command: make dll-ordered-list
dll-ordered-list: dll-ordered-list.o
	$(CC) $(CFLAGS) -o dll-ordered-list dll-ordered-list.o

dll-ordered-list.o: dll-ordered-list.c
	$(CC) $(CFLAGS) -c dll-ordered-list.c

test-memory-dll-ordered-list: dll-ordered-list
	valgrind --leak-check=full ./dll-ordered-list
	
execute-dll-ordered-list: dll-ordered-list
	./dll-ordered-list


# Compilation for the dll-ordered-list-stretch.c
# Command: make dll-ordered-list-stretch
dll-ordered-list-stretch: dll-ordered-list-stretch.o
	$(CC) $(CFLAGS) -o dll-ordered-list-stretch dll-ordered-list-stretch.o

dll-ordered-list-stretch.o: dll-ordered-list-stretch.c
	$(CC) $(CFLAGS) -c dll-ordered-list-stretch.c

test-memory-dll-ordered-list-stretch: dll-ordered-list-stretch
	valgrind --leak-check=full ./dll-ordered-list-stretch
	
execute-dll-ordered-list-stretch: dll-ordered-list-stretch
	./dll-ordered-list


# Make all
all: dll-ordered-list dll-ordered-list-stretch

# Make clean
clean:
	rm -rf *.o *.swp dll-ordered-list dll-ordered-list-stretch

