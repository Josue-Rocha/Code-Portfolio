'''
Title:      balanced.py
Abstract:   Determine wether or not a binary tree is balanced.
Author:     Josue Rocha
Email:      jrocha3@nd.edu
Estimate:   45 minutes
Date:       04/04/2023
Questions:
    1. What is the worst-case time complexity of is_balanced()?
        O(n)
    2. What information does is_balanced() return?
        Whether or not the tree is balanced, and the height of the tree
'''

import sys

# Functions

def is_balanced(array, index=0):
    ''' Determine whether or not a binary tree is balanced.
    A binary tree is balanced if:
    1. Left and right sub-trees are balanced.
    2. Difference between heights of left and right sub-trees is no more than 1.
    >>> is_balanced([5, 3, 6])
    (True, 2)
    >>> is_balanced([5, 3, 6, 4])
    (True, 3)
    >>> is_balanced([5, 3, 0, 4])
    (False, 3)
    >>> is_balanced([5, 3, 4, 0, 1])
    (True, 3)
    >>> is_balanced([5, 3, 4, 0, 1, 0, 0, 0, 0, 2])
    (False, 4)
    '''
    if index >= len(array) or not array[index]:
        return True, 0

    # Divide and Conquer and Combine
    balance, left_height     = is_balanced(array, 2*index + 1)
    balance, right_height    = is_balanced(array, 2*index + 2)

    return abs(left_height - right_height) <= 1, max(left_height, right_height) +1

# Main Execution

def main(stream=sys.stdin):
    ''' For each line with a tree given in BFS format, output whether or not it
    is balanced.
    >>> import io
    >>> main(io.StringIO('5 3 6\\n5 3 6 4\\n5 3 0 4\\n'))
    Balanced
    Balanced
    Not Balanced
    '''
    for item in stream:
        item = item.strip()
        item = item.split()

        for i in range(0, len(item)):
            item[i] = int(item[i])

        bool_val, num = is_balanced(item)
        if bool_val:
            print('Balanced')
        else:
            print('Not Balanced')


if __name__ == '__main__':
    main()
