#!/usr/bin/env python3

'''
Title:      collatz.py
Abstract:   Compute the Collatz cycle length using memoization.
Author:     Josue Rocha
Email:      jrocha3@nd.edu
Estimate:   30 minutes
Date:       04/25/2023
Questions:

    1. What is stored in the table passed to cycle_length()?
        The "current" cycle length

    2. How is table used in cycle_length() to implement memoization?
        To check to see if we alread calculated that number

    3. What number between 100 and 1000 (inclusive) has the longest cycle
    length?
        871
'''

from table import Map

import sys

# Functions

def cycle_length(n, table):
    ''' Return the collatz cycle length.

    >>> cycle_length(22, Map())
    16

    >>> cycle_length(58, Map())
    20

    >>> cycle_length(71, Map())
    103

    >>> cycle_length(1337, Map())
    45
    '''
    if n == 1:
      return 1

    value = table.lookup(n)

    # check if we already calculated it
    if value:
      return value

    if n % 2 == 0:
        length = 1 + cycle_length(n // 2, table) # recursive case if even
    else:
        length = 1 + cycle_length(3 * n + 1, table) # recursive case if odd
    
    # add the "current" length
    table.insert(n, length)

    return length

# Main Execution

def main(stream=sys.stdin):
    ''' For each number in standard input, compute the cycle length, and print
    it out.

    >>> import io
    >>> main(io.StringIO('22\\n58\\n71\\n1337\\n'))
    Cycle Length of 22: 16
    Cycle Length of 58: 20
    Cycle Length of 71: 103
    Cycle Length of 1337: 45
    '''
    for item in stream:
        item = item.strip()
        length = cycle_length(int(item),  Map())
        print(f"Cycle Length of {item}: {length}")
    pass

if __name__ == '__main__':
    main()
