#!/usr/bin/env python3

import os
import sys

# Functions

def usage(status=0):
    ''' Display usage message and exit with status. '''
    progname = os.path.basename(sys.argv[0])
    print(f'''Usage: {progname} [flags]

    -c      Prefix lines by the number of occurences
    -d      Only print duplicate lines
    -i      Ignore differences in case when comparing, prints out full line in lowercase
    -u      Only print unique lines

By default, {progname} prints one of each type of line.''')
    sys.exit(status)

def count_frequencies(stream=sys.stdin, ignore_case=False):
    ''' Count the line frequencies from the data in the specified stream while
    ignoring case if specified. '''
    frequencies = {}

    for line in stream:
        line = line.rstrip()
        if ignore_case:
            line = line.lower()
        frequencies[line] = frequencies.get(line, 0) + 1

    '''for line in sys.stdin:
        line = line.rstrip()
        frequencies[line] = frequencies.get(line, 0) +1'''
    return frequencies
    #pass

def print_lines(frequencies, occurrences=False, duplicates=False, unique_only=False):
    ''' Display line information based on specified parameters:

    - occurrences:  if True, then prefix lines with number of occurrences
    - duplicates:   if True, then only print duplicate lines
    - unique_only:  if True, then only print unique lines
    '''

    if duplicates and unique_only:
        usage(1)
    else:
        for key, value in frequencies.items():
            if duplicates and value <= 1:
                continue
            if unique_only and value != 1:
                continue
            if occurrences:
                if duplicates:
                    print(f'{value:>7} {key}')
                elif unique_only:
                    print(f'{value:>7} {key}')
                else:
                    print(f'{value:>7} {key}')
            elif duplicates:
                print(key)
            elif unique_only:
                print(key)
            else:
                print(key)
    
    #pass

def main():
    ''' Process command line arguments, count frequencies from standard input,
    and then print lines. '''

    arguments = sys.argv[1:]
    freq = {}

    ignore_case = False
    occurrences = False
    duplicates  = False
    unique_only = False

    while len(arguments) and arguments[0].startswith('-'):
        argument = arguments.pop()
        if argument == '-c':
            occurrences = True
        elif argument == '-d':
            duplicates = True
        elif argument == '-i':
            ignore_case = True
        elif argument == '-u':
            unique_only = True
        elif argument == '-h':
            usage(0)
        else:
            usage(1)

    if ignore_case:
        freq = count_frequencies(ignore_case = True)
    else:
        freq = count_frequencies()

    print_lines(freq, occurrences=occurrences, duplicates=duplicates, unique_only=unique_only)
    #pass

# Main Execution

if __name__ == '__main__':
    main()

# vim: set sts=4 sw=4 ts=8 expandtab ft=python:
