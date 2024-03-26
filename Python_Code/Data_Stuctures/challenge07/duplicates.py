'''
Title:      duplicates.py
Abstract:   Determine whether or not a line of words contains any duplicates.
Author:     Josue Rocha
Email:      jrocha3@nd.edu
Estimate:   45 minutes
Date:       04/04/2023
Questions:
    1. What is the average time complexity of detect_duplicates()?
        O(log(n))
    2. What is the worst-case time complexity of detect_duplicates()?
        O(n)
    3. What is the worst-case space complexity of detect_duplicates()?
        O(n)
    4. How would you modify the program to make it case in-sensitive?
        You convert all the letters to lowercase (or uppercase)
'''

import sys

from set import Set

# Functions

def detect_duplicates(words):
    ''' Return whether or not the sequence of words contains a duplicate.
    >>> detect_duplicates('a b c'.split())
    False
    >>> detect_duplicates('a b a'.split())
    True
    >>> detect_duplicates('a b c b e f'.split())
    True
    '''
    s = Set()
    for word in words:
        if s.search(word):
            return True
        s.insert(word)
    return False

# Main Execution

def main(stream=sys.stdin):
    ''' For each line of words, determine if there are any duplicates.
    >>> import io
    >>> main(io.StringIO('a b c\\na b a\\na b c b e f\\n'))
    False
    True
    True
    '''
    for item in stream:
        item = item.strip()
        item = item.split()
        print(detect_duplicates(item))

if __name__ == '__main__':
    main()
