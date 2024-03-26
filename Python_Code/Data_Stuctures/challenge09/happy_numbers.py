#!/usr/bin/env python3

'''
Title:      happy_numbers.py
Abstract:   Determine if a number is a happy number or not using memoization.
Author:     Josue Rocha
Email:      jrocha3@nd.edu
Estimate:   30 minutes
Date:       04/25/2023
Questions:

    1. How is seen used in is_happy()?
    To see if a number was already process, this means that we would enter a loop which will never end in 1, so it is not a happy number

    2. How is table used in is_happy() to implement memoization?
    To store the actual calculations (sum of the squares of the digits) and see if it was already calcuated

    3. How many happy numbers are there between 1 and 100 (inclusive)?

        20
'''

from table import Map

import sys

# Functions

def is_happy(n, seen, table):
    ''' Return whether or not n is a happy number.

    >>> is_happy(19, Map(), Map())
    True

    >>> is_happy(2, Map(), Map())
    False

    >>> is_happy(68, Map(), Map())
    True

    >>> is_happy(75, Map(), Map())
    False

    >>> is_happy(91, Map(), Map())
    True
    '''
    # Bases Case: number is a happy number
    if n == 1:
      return True
    
    # Means we have already seen this value, so the number is not a happy number
    svalue = seen.lookup(n)
    if (svalue):
      return False
    
    # Add value to seen, in case it comes up again
    seen.insert(n, 1)

    # Check to see if we alread calculated this
    tvalue = table.lookup(n)
    if tvalue:
      return is_happy(tvalue, seen, table) # Recursive Case

    # Calculate the sum of squares of digits of the number
    square_sum = sum(int(digit) ** 2 for digit in str(n))

    # Add the calculation
    table.insert(n, square_sum)

    # Also Recursive case
    return is_happy(square_sum, seen, table)


# Main Execution

def main(stream=sys.stdin):
    ''' For each number in standard input, determine if it is a happy number,
    and print it out.

    >>> import io
    >>> main(io.StringIO('19\\n2\\n68\\n75\\n91\\n'))
    Is 19 Happy?: Yes
    Is 2 Happy?: No
    Is 68 Happy?: Yes
    Is 75 Happy?: No
    Is 91 Happy?: Yes
    '''
    for item in stream:
        item = item.strip()
        if(is_happy(item, Map(), Map())):
            print(f"Is {item} Happy?: Yes")
        else:
            print(f"Is {item} Happy?: No")

if __name__ == '__main__':
    main()
