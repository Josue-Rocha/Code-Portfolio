'''
Title:      anagrams.py
Abstract:   Determine if two words are anagrams.
Author:     Domer McDomerson
Email:      dmcdomer@nd.edu
Estimate:   30 minutes
Date:       11/07/2022
Questions:
    1. What is the worst-case time complexity for count_letters()?
        O(nlogn)
    2. What is the worst-case time complexity ofr is_anagram()?
        O(nlogn)
'''

from treap import Map

import sys

# Functions

def count_letters(word):
    ''' Counts the occurrences of each letter in word and stores it in a Map
    (case insensitive).
    >>> counts = count_letters('aBbCcC')
    >>> counts.lookup('a')
    1
    >>> counts.lookup('b')
    2
    >>> counts.lookup('c')
    3
    >>> counts.lookup('d')
    '''
    m = Map()
    word = word.lower() # convert to lower cause it's case insensitive
  
    for letter in word:
      val = m.lookup(letter)
      if val is None:
        m.insert(letter, 1) # add letter to the treap
      else:
        m.insert(letter, val+1) # update the count for the letter
    return m

def is_anagram(word_a, word_b):
    ''' Returns whether or not two words are anagrams.
    >>> is_anagram('anna', 'naan')
    True
    >>> is_anagram('banana', 'aNaNaB')
    True
    >>> is_anagram('SiLeNt', 'listen')
    True
    >>> is_anagram('KeK', 'eek')
    False
    >>> is_anagram('Nope', 'Topen')
    False
    >>> is_anagram('taco', 'cat')
    False
    '''
    a = count_letters(word_a)
    b = count_letters(word_b)
    
    # In case the words are different lengths (by definition, they can't be anagrams)
    if len(word_a) != len(word_b):
      return False

    # Only need to check every letter for one of the words
    for letter in word_a:
      if(a.lookup(letter) != b.lookup(letter)):
        return False
    return True
# Main Execution

def main(stream=sys.stdin):
    ''' For each pair of words on each line, determine if they are anagrams,
    and print out the result.
    >>> import io
    >>> main(io.StringIO('taco cat\\nanna naan\\nSiLeNt listen\\n'))
    taco and cat are not anagrams!
    anna and naan are anagrams!
    SiLeNt and listen are anagrams!
    '''

    # parse arguments in stream
    for item in stream:
        item = item.strip()
        item = item.split()
        if(is_anagram(item[0], item[1])):
            print(f'{item[0]} and {item[1]} are anagrams!')
        else:
            print(f'{item[0]} and {item[1]} are not anagrams!')

if __name__ == '__main__':
    main()
