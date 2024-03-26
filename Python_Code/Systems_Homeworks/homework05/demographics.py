#!/usr/bin/env python3

import collections
import os
import sys
import csv

import requests

# Constants

URL     = 'https://yld.me/raw/e2Ad'
TAB     = ' '*8
GENDERS = ('M', 'F')
ETHNICS = ('B', 'C', 'N', 'O', 'S', 'T', 'U')

# Functions

def usage(status=0):
    ''' Display usage information and exit with specified status '''
    progname = os.path.basename(sys.argv[0])
    print(f'''Usage: {progname} [options] [URL]

    -y  YEARS   Which years to display (default: all)
    -p          Display data as percentages.
    -G          Do not include gender information.
    -E          Do not include ethnic information.
    ''')
    sys.exit(status)

def load_demo_data(url=URL):
    ''' Load demographics from specified URL into dictionary

    >>> load_demo_data('https://yld.me/raw/ilG').keys()
    dict_keys(['2013', '2014', '2015', '2016', '2017', '2018', '2019'])

    >>> load_demo_data('https://yld.me/raw/ilG')['2013'] == {'M': 1, 'B': 2, 'F': 1, 'TOTAL': 2}
    True

    >>> load_demo_data('https://yld.me/raw/ilG')['2019'] == {'M': 1, 'U': 2, 'F': 1, 'TOTAL': 2}
    True
    '''
    # TODO: Request data from url and load it into dictionary organized in the
    # following fashion:
    #
    #   {'year': {'gender': count, 'ethnic': count, 'TOTAL': count}}
    response = requests.get(url)
    response = response.text
    response = response.splitlines()
    total = 0
    data = {}

    for student in csv.reader(response):
        year = student[0]
        gender = student[1]
        ethnic = student[2]

        if year == 'Year':
            continue
        if year not in data:
            data[year] = {}
        if gender not in data[year]:
            data[year][gender] = 0
        if ethnic not in data[year]:
            data[year][ethnic] = 0

        data[year][gender]  += 1
        data[year][ethnic]  += 1

    for year in data:
        if 'TOTAL' not in data[year]:
            data[year]['TOTAL'] = 0
        data[year]['TOTAL'] = data[year]['M'] + data[year]['F']
    return data
def print_demo_separator(years, char='='):
    ''' Print demographics separator

    Note: The row consists of the 8 chars for each item in years + 1.

    >>> print_demo_separator(['2012', '2013'])
    ========================
    '''
    # TODO: Print row of separator characters
    for i in range(0, len(years)+1):
        for i in range(0,8):
            print(f'{char}',end="")
    print()

def print_demo_years(years):
    ''' Print demographics years row

    Note: The row is prefixed by 4 spaces and each year is right aligned to 8
    spaces ({:>8}).

    >>> print_demo_years(['2012', '2013'])
            2012    2013
    '''
    # TODO: Print row of years
    print('    ',end="")
    for year in years:
        if year == 'Year':
            continue
        print(f'{year:>8}',end="")
    print()

def print_demo_fields(data, years, fields, percent=False):
    ''' Print demographics information (for particular fields)

    Note: The first column should be a 4-spaced field name ({:>4}), followed by
    8-spaced right aligned data columns ({:>8}).  If `percent` is True, then
    display a percentage ({:>7.1f}%) rather than the raw count.

    >>> data  = load_demo_data('https://yld.me/raw/ilG')
    >>> years = sorted(data.keys())
    >>> print_demo_fields(data, years, GENDERS, False)
       M       1       1       1       1       1       1       1
       F       1       1       1       1       1       1       1
    '''
    # TODO: For each field, print out a row consisting of data from each year.
    for item in fields:
        print(f'{item:>4}',end="")
        if percent:
            for year in years:
                if year == 'Year':
                    continue
                info = (data[year][item]/data[year]['TOTAL']) * 100
                print(f'{info:>7.1f}%',end='')
            print()
        else:
             for year in years:
                if year == 'Year':
                    continue
                info = data[year][item]
                print(f'{info:>8}',end='')
             print()

def print_demo_gender(data, years, percent=False):
    ''' Print demographics gender information '''
    print_demo_fields(data, years, GENDERS, percent)
    print_demo_separator(years, '-')

def print_demo_ethnic(data, years, percent=False):
    ''' Print demographics ethnic information '''
    print_demo_fields(data, years, ETHNICS, percent)
    print_demo_separator(years, '-')

def print_demo_data(data, years=None, percent=False, gender=True, ethnic=True):
    ''' Print demographics data for the specified years and attributes '''
    # TODO: Verify the years parameter (if None then extract from data,
    if not years:
        years = sorted(data.keys())
    # otherwise use what is given).  Ensure years is sorted.
    pass
    years = sorted(years)

    # TODO: Print years header with separator
    print_demo_years(years)
    print_demo_separator(years)

    # TODO: Print gender and ethic data if enabled
    if gender:
        print_demo_gender(data, years, percent=percent)
    if ethnic:
        print_demo_ethnic(data, years, percent=percent)
                    

'''def print_demo_gender(data, years, percent=False):
    print_demo_fields(data, years, GENDERS, percent)
    print_demo_separator(years, '-')

def print_demo_ethnic(data, years, percent=False):
    print_demo_fields(data, years, ETHNICS, percent)
    print_demo_separator(years, '-')'''

def main():
    ''' Parse command line arguments, load data from url, and then print
    demographic data. '''
    # TODO: Parse command line arguments
    arguments = sys.argv[1:]
    url       = URL
    years     = None
    gender    = True
    ethnic    = True
    percent   = False
    test      = None
    for index, argument in enumerate(arguments):
        if argument.startswith('-'):
            if argument == '-y':
                user_i = arguments[index+1]
                years = []
                for i in user_i.split(','):
                    years.append(i)
            elif argument == '-p':
                percent = True
            elif argument == '-G':
                gender = False
            elif argument == '-E':
                ethnic = False
            elif argument == '-h':
                usage(0)
            else:
                usage(1)
        test = arguments[index] 
    # TODO: Load data from url and then print demograpic data with specified
    # arguments
    if test and test.startswith('http'):
        url = test

    data = load_demo_data(url)

    for year in data:
        for eth in ETHNICS:
            if eth not in data[year]:
                data[year][eth] = 0

    '''if not years:
        years = []
        for i, year in enumerate(data):
            if i:
                years.append(year)'''
    
    print_demo_data(data, years=years, percent=percent, gender=gender, ethnic=ethnic)

# Main Execution

if __name__ == '__main__':
    main()

# vim: set sts=4 sw=4 ts=8 expandtab ft=python:
