#!/usr/bin/env python3

'''
Title: selection-sort-recursive.py
Abstract: A Program that does a recursive selection sort on a list given by the user
Author: Josue Rocha
Email: jrocha3@student10.cse.nd.edu
Estimate: 1 hour 
Date: 03/23/2023
'''

# swap the two numbers in the array
def switch(arr, i, j):
    tmp = arr[i]
    arr[i] = arr[j]
    arr[j] = tmp

def rec_selection_sort(arr, i, n):
    minimum = i

    for j in range(i+1, n):
        if arr[j] < arr[minimum]:
            minimum = j
    switch(arr, minimum, i)
    
    # recursive case
    if i + 1 < n:
        rec_selection_sort(arr, i+1, n)

# print the array
def print_arr(arr, size):
    print('The sorted list is: ', end='')
    for i in range(size):
        print(f'{arr[i]} ', end='')
    print()

my_list = []
print('Enter numbers to add to array, press "q" to end and sort\n')

while 1:
    user_input = input('Enter number to add to the array: ')
    if user_input == 'q':
        break
    user_input = int(user_input) # type cast the user input
    my_list.append(user_input)
    print(f'The current array is: {my_list}\n')

size = len(my_list)
rec_selection_sort(my_list, 0, size)
print_arr(my_list, size)
