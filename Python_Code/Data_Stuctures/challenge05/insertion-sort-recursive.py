#!/usr/bin/env python3

'''
Title: insertion-sort-recursive.py
Abstract: A Program that does a recursive insertion sort on a list given by the user
Author: Josue Rocha
Email: jrocha3@student10.cse.nd.edu
Estimate: 1/ hour 
Date: 03/23/2023
'''

def rec_insertion_sort(arr,n):
   # base case
   if n<=1:
      return
   # recursive case
   rec_insertion_sort(arr,n-1)
   num = arr[n-1]
   j = n-2
   # move ahead
   while (j>=0 and arr[j]>num):
      arr[j+1] = arr[j]
      j = j-1
   arr[j+1]=num

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
    print(f'The array currently is: {my_list}\n')

size = len(my_list)
rec_insertion_sort(my_list, size)
print_arr(my_list, size)
