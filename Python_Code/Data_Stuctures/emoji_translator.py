#!/usr/bin/env python3

'''
Title:      emoji_translator.py
Abstract:   Translate text commands to emojis.
Author:     Josue Rocha
Email:      jrocha3@nd.edu
Estimate:   25 minutes
Date:       11/08/2022
Questions:

    1. What is the average time complexity of substitute_emojis()?
        O(n) - Where n is the number of words
    2. How did you check if a word was enclosed by ':'?
        I used the if statement: "if  word.stratswith(':') and word.enswith(':')"
    3. How did you separate the word from the enclosing ':'?
        I used slicing: "word = word[1:-1]" this cuts off the fist and last character of the word
'''

import sys

# Constants

EMOJIS = {
    'football': '🏈',
    'python'  : '🐍',
    'heart'   : '♥',
    'rocket'  : '🚀',
    'shamrock': '☘',
}

# Functions

def substitute_emojis(text):
    ''' Substitute any words enclosed in : with the corresponding emojis in the
    EMOJIS table.

    If the word is not the table, then return the original word.

    >>> substitute_emojis('i :heart: :python:')
    'i ♥ 🐍'

    >>> substitute_emojis(':shamrock: :Notre: Dame :football: :rocket:\\n')
    '☘ Notre Dame 🏈 🚀'
    '''

    new_str = ' '
    words_list = []
    for word in text.split():
        if word.startswith(':') and word.endswith(':'):
            word = word[1:-1]
            try:
                words_list.append(EMOJIS[word])
            except KeyError:
                words_list.append(word)
        else:
            words_list.append(word)
    return new_str.join(words_list)

# Main Execution

def main(stream=sys.stdin):
    ''' For each line in standard input, substitute any emojis, and then print
    the translation.

    >>> import io
    >>> main(io.StringIO('i :heart: :python:\\n:shamrock: :Notre: Dame :football: :rocket:\\n'))
    i ♥ 🐍
    ☘ Notre Dame 🏈 🚀
    '''
    for item in stream:
        item = item.strip()
        print(substitute_emojis(item))

if __name__ == '__main__':
    main()
