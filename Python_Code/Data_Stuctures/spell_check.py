#!/usr/bin/env python3

'''
Title:      spell_check.py
Abstract:   Simple spell checker using different data structures.
Author:     Josue Rocha
Email:      jrocha3@nd.edu
Estimate:   25 minutes
Date:       11/08/2022
Questions:

    1. What is the average time complexity of searching the words list?

     O(n), To see if a word is in the list, you need to check every element in the lis.t   

    2. What is the average time complexity of searching the words set?

     O(1), python sets internally use a hash table which have an O(1) search complexity.   

    3. How would you modify the spellchecker to ignore punctuation (ie.
    "donate," or "anyone.")?

        You coudl add a provision to check if each letter in the word is actually a letter, and if it is not, remove it or check a copied version of the word without the punctuation

    4. How fast is using a set vs a list to perform spell check?

        Using a set is .001 seconds faster
'''

import sys

# Constants

WORDS_PATH ='/usr/share/dict/words'

# Functions

def load_words_list(words_path=WORDS_PATH):
    ''' Load words file into list. 

    >>> words = load_words_list()
    >>> isinstance(words, list)
    True

    >>> 'notre' in words
    True
    
    >>> 'dame' in words
    True
    
    >>> 'football' in words
    True

    >>> 'asdfafdasdfjkl;j' in words
    False
    '''

    words_list = []
    for word in open(words_path):
        word = word.strip()

        if word == '\n':
            continue

        words_list.append(word.lower())

    return words_list

def load_words_set(words_path=WORDS_PATH):
    ''' Load words file into set. 

    >>> words = load_words_set()
    >>> isinstance(words, set)
    True

    >>> 'notre' in words
    True
    
    >>> 'dame' in words
    True
    
    >>> 'football' in words
    True

    >>> 'asdfafdasdfjkl;j' in words
    False
    '''

    words_set = set()
    for word in open(words_path):
        word = word.strip()

        if word == '\n':
            continue

        words_set.add(word.lower())

    return words_set

# Main Execution

def main(stream=sys.stdin, use_set=False):
    ''' For each word in standard input, check if it is in the words file.

    If use_set is True, load the words into a set, otherwise, load the words
    into a list.
    
    You should ignore case when checking, but print the original word if it is
    not in the words file.

    >>> import copy, io
    >>> sio = io.StringIO('Notre Dame Football\\nFreeman era\\nJust runthedamnball\\n') 
    >>> main(copy.copy(sio))
    runthedamnball
    
    >>> main(copy.copy(sio), True)
    runthedamnball
    '''
    if use_set:
        words_file = load_words_set()
    else:
        words_file = load_words_list()

    sentence = stream.readline().strip().split()

    while(sentence):
        for word in sentence:
            if word.lower() not in words_file:
                print(word)
        sentence = stream.readline().strip().split()



if __name__ == '__main__':
    main(use_set=len(sys.argv) > 1 and sys.argv[1] == '-s')
