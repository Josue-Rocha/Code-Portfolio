#!/usr/bin/env python3

'''
Title: priority-que.py
Abstract: A Program that implements a priority que in python
Author: Josue Rocha
Email: jrocha3@student10.cse.nd.edu
Estimate: 45 minutes 
Date: 03/23/2023
'''

#print the queue
def print_arr(arr):
    if len(arr):
        for i in arr:
            print(f'{i} ',end='')
        print()
    else:
        print('The Queue is empty')

def IsEmpty(arr):
    if len(arr): # check size of the queue to see if there is anything
        return 1
    else:
        return 0

def enque(arr, num):
    # in case queue is empty
    if not len(arr):
        arr.append(num)
        return arr

    index = len(arr)
    
    # look for the correct position of the new number
    for i in range(len(arr)):
        if arr[i] > num:
            index = i
            break

    if index == len(arr):
        arr.append(num)
    else:
        # insert number into the queue
        arr = arr[:index] + [num] + arr[index:]
    return arr
        
def deque(arr):
    if not len(arr):
        print('Queue is already empty')
    else:
        # remove the first element of the queue (which is also the smalles) and free the memory
        arr.pop(0)

queue = []
print('Choose your option:\n1. Enque\n2. Deque\n3. IsEmpty\n4. Display\n5. Quit\n')


while 1:
    choice = input('Enter your choice: ')
    choice = int(choice)
    # check to see if the user wants to end the program first
    if choice == 5:
        break
    elif choice == 1:
        num = input('Enter number to place in Queue: ')
        queue = enque(queue, int(num))
        print('The Queue is: ',end='')
        print_arr(queue)
    elif choice == 2:
        deque(queue)
        print('The Queue is: ',end='')
        print_arr(queue)
    elif choice == 3:
        val = IsEmpty(queue)
        if val:
            print('The Queue is not empty, it is: ', end='')
            print_arr(queue)
        else:
            print('The Queue is empty right now')
    elif choice == 4:
        print('The Queue is: ',end='')
        print_arr(queue)
    else:
        print('Error, invalid choice, please try again')
    print()
