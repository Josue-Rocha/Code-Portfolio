#!/usr/bin/env python3

'''
Title:      center_star.py
Abstract:   Determine center of star graph.
Author:     Domer McDomerson
Email:      dmcdomer@nd.edu
Estimate:   30 minutes
Date:       11/30/2022
Questions:

    1. If you did not use a defaultdict to represent the graph, how else could
    you have added the edges to the adjaceny list (describe one alternative
    approach)?

        Create a list of n empty lists before resding the input.

    2. What is the average time complexity of find_center?

        O(logn)
'''

import io
import sys

from collections import defaultdict

# Functions

def read_graph(stream=sys.stdin):
    ''' Read one graph from the stream.

    >>> read_graph(io.StringIO('3\\n1 2\\n2 3\\n4 2\\n'))
    defaultdict(<class 'list'>, {1: [2], 2: [1, 3, 4], 3: [2], 4: [2]})

    >>> read_graph(io.StringIO('4\\n1 2\\n5 1\\n1 3\\n1 4\\n'))
    defaultdict(<class 'list'>, {1: [2, 5, 3, 4], 2: [1], 5: [1], 3: [1], 4: [1]})

    >>> read_graph(io.StringIO('4\\n1 2\\n5 1\\n1 3\\n2 4\\n'))
    defaultdict(<class 'list'>, {1: [2, 5, 3], 2: [1, 4], 5: [1], 3: [1], 4: [2]})
    '''
    
    d = defaultdict(list)
    
    try:
        n = int(stream.readline())
    except ValueError:
        return None

    for i in range(n):
        n1, n2 = stream.readline().split()

        n1 = int(n1)
        n2 = int(n2)

        d[n1].append(n2)
        d[n2].append(n1)

    return d

def find_center(graph):
    ''' Find center vertex of star graph.

    >>> find_center(read_graph(io.StringIO('3\\n1 2\\n2 3\\n4 2\\n')))
    2

    >>> find_center(read_graph(io.StringIO('4\\n1 2\\n5 1\\n1 3\\n1 4\\n')))
    1

    >>> find_center(read_graph(io.StringIO('4\\n1 2\\n5 1\\n1 3\\n2 4\\n')))
    '''

    n = len(graph) - 1

    for k, v in graph.items():
        if len(v) == n:
            return k
    return None

# Main Execution

def main(stream=sys.stdin):
    ''' For each graph, determine which vertex is the center of the star graph,
    and print it out.

    >>> main(io.StringIO('3\\n1 2\\n2 3\\n4 2\\n4\\n1 2\\n5 1\\n1 3\\n1 4\\n4\\n1 2\\n5 1\\n1 3\\n2 4\\n'))
    Vertex 2 is the center
    Vertex 1 is the center
    There is no center
    '''

    while graph := read_graph(stream):
        center = find_center(graph)
        if center:
            print(f'Vertex {center} is the center')
        else:
            print('There is no center')



if __name__ == '__main__':
    main()
