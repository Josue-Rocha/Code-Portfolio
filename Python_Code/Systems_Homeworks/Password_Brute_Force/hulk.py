#!/usr/bin/env python3

import concurrent.futures
import hashlib
import os
import string
import sys

# Constants

ALPHABET = string.ascii_lowercase + string.digits

# Functions

def usage(exit_code=0):
    progname = os.path.basename(sys.argv[0])
    print(f'''Usage: {progname} [-a ALPHABET -c CORES -l LENGTH -p PATH -s HASHES]
    -a ALPHABET Alphabet to use in permutations
    -c CORES    CPU Cores to use
    -l LENGTH   Length of permutations
    -p PREFIX   Prefix for all permutations
    -s HASHES   Path of hashes file''')
    sys.exit(exit_code)

def md5sum(s):
    ''' Compute md5 digest for given string. '''
    # TODO: Use the hashlib library to produce the md5 hex digest of the given
    # string.
     
    result = hashlib.md5(s.encode())
    return result.hexdigest()

def permutations(length, alphabet=ALPHABET):
    ''' Recursively yield all permutations of alphabet up to given length. '''
    # TODO: Use yield to create a generator function that recursively produces
    # all the permutations of the given alphabet up to the provided length.
    if length == 1:
        for letter in alphabet:
            yield letter
    else:
        for letter in alphabet:
            for perm in permutations(length-1, alphabet):
                yield letter + perm

def flatten(sequence):
    ''' Flatten sequence of iterators. '''
    # TODO: Iterate through sequence and yield from each iterator in sequence.
    for iterable in sequence:
        for item in iterable:
            yield item

def crack(hashes, length, alphabet=ALPHABET, prefix=''):
    ''' Return all password permutations of specified length that are in hashes
    by sequentially trying all permutations. '''
    # TODO: Return list comprehension that iterates over a sequence of
    # candidate permutations and checks if the md5sum of each candidate is in
    # hashes.
    return [prefix + candidate for candidate in permutations(length, alphabet) if md5sum(prefix + candidate) in hashes]

def whack(arguments):
    ''' Call the crack function with the specified list of arguments '''
    return crack(hashes=arguments[0], length=arguments[1], alphabet=arguments[2], prefix=arguments[3])

def smash(hashes, length, alphabet=ALPHABET, prefix='', cores=1):
    ''' Return all password permutations of specified length that are in hashes
    by concurrently subsets of permutations concurrently.
    '''
    # TODO: Create generator expression with arguments to pass to whack and
    # then use ProcessPoolExecutor to apply whack to all items in expression.
    arguments = ((hashes, length-1, alphabet, prefix+letter) for letter in alphabet) 

    with concurrent.futures.ProcessPoolExecutor(cores) as executor:
        return flatten(executor.map(whack, arguments))
    
# Main Execution

def main():
    arguments   = sys.argv[1:]
    alphabet    = ALPHABET
    cores       = 1
    hashes_path = 'hashes.txt'
    length      = 1
    prefix      = ''

    # TODO: Parse command line arguments
    for index, argument in enumerate(arguments):
        if argument.startswith('-'):
            if argument == '-a':
                alphabet = arguments[index + 1]
            elif argument == '-c':
                cores = int(arguments[index + 1])
            elif argument == '-l':
                length = int(arguments[index + 1])
            elif argument == '-p':
                prefix = arguments[index + 1]
            elif argument == '-s':
                hashes_path = arguments[index + 1]
            elif argument == '-h':
                usage(0)
            else:
                usage(1)
    
    # TODO: Load hashes set
    #hash_set = set([line for line in open(hashes_path, 'r')])
    hashes = set((line.strip() for line in open(hashes_path, 'r')))
    #passwords = []
    
    # TODO: Execute crack or smash function
    if length == 1 or cores == 1:
        passwords = crack(hashes=hashes, length=length, alphabet=alphabet, prefix=prefix)
    else:
        passwords = smash(hashes=hashes, length=length, alphabet=alphabet, prefix=prefix, cores=cores)

    # TODO: Print all found passwords
    for password in passwords:
        print(password)
if __name__ == '__main__':
    main()
