#!/usr/bin/env python3

'''
Title: closest-numbers.py
Abstract: A program that reads in a list to find and print the pair of elements that have the smallest absolute difference between them
Author: Josue Rocha
Email: jrocha3@student10.cse.nd.edu
Estimate: 1/2 hour 
Date: 03/23/2023
'''

def print_dist(arr):
    # since the list is sorted, we set the first dist value to the max - min which will then be compared and guarantee that this initial value will be bigger then the shortest distance, thus we know we won't miss the shortest distance when we loop though the array.
    dist = max(arr) - min(arr)

    for i in range(len(arr)-1):
        if (arr[i+1] - arr[i]) < dist: # compare the dist between the two numbers between whatever the current dist value is
            dist = arr[i+1] - arr[i]
    for i in range(len(arr)-1):
        if (arr[i+1]-arr[i]) == dist: # find all pairs that have the same dist value with them
            print(arr[i], arr[i+1])

file_name = input('Enter file name: ')
# open file specified by the user
the_file = open(file_name, 'r')
the_file = the_file.read().splitlines()
#size = int(the_file.pop(0)) get the size, but this isn't really nedded for my code
the_list = []

# put all of the numbers in a list
for num in the_file[1].split():
    the_list.append(int(num))

the_list.sort()

print_dist(the_list)
