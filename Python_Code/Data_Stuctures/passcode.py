#!/usr/bin/env python3

'''
Title:      passcode.py
Abstract:   Use topological sort to crack the passcode.
Author:     Peter Bui
Email:      pbui@nd.edu
Estimate:   30 minutes
Date:       12/7/2022
Questions:

    1. What does compute_degrees produce?

        A (default) dicitonary of ints, with the computed degrees (the numbers of things that a particular vertex in a graph "relys" on)
    2. What is the average time complexity of compute_degrees?
        O(V+E), V = # of vertices, E = # of Edges
    3. What is the average time complexity of topological sort?
        O(V+E), V = # of Vertices, E = # of Edges
    4. What is the average space complexity of topological sort?
        O(V), V = # of Vertices
'''

import collections
import io
import sys

# Constants

SAMPLE_CODES = [352, 154, 542, 315, 152]
LONGER_CODES = [219, 183, 804, 376, '043', 904, 357, 857, 206, 180, 983, 284, 843]


# Functions

def read_graph(stream=sys.stdin):
    ''' Read codes into graph (adjacency set).

    >>> read_graph(io.StringIO('\\n'.join(map(str, SAMPLE_CODES))))
    defaultdict(<class 'set'>, {3: {1, 5}, 5: {2, 4}, 1: {5}, 4: {2}})

    >>> read_graph(io.StringIO('\\n'.join(map(str, LONGER_CODES))))
    defaultdict(<class 'set'>, {2: {0, 1, 8}, 1: {8, 9}, 8: {0, 3, 4, 5}, 0: {4, 6}, 3: {5, 7}, 7: {6}, 4: {3}, 9: {0, 8}, 5: {7}})
    '''

    d = collections.defaultdict(set)

    codes = stream.readline().strip()
    while(codes):
        codes = str(codes)
        codes_list = [digit for digit in codes]

        for i in range(len(codes_list)):
            codes_list[i] = int(codes_list[i])

        d[codes_list[0]].add(codes_list[1])
        d[codes_list[1]].add(codes_list[2])

        codes = stream.readline().strip()
    return d

def compute_degrees(graph):
    ''' Compute degrees of all vertices in graph.

    >>> compute_degrees(read_graph(io.StringIO('\\n'.join(map(str, SAMPLE_CODES)))))
    defaultdict(<class 'int'>, {3: 0, 1: 1, 5: 2, 2: 2, 4: 1})

    >>> compute_degrees(read_graph(io.StringIO('\\n'.join(map(str, LONGER_CODES)))))
    defaultdict(<class 'int'>, {2: 0, 0: 3, 1: 1, 8: 3, 9: 1, 3: 2, 4: 2, 5: 2, 6: 2, 7: 2})
    '''

    degrees = collections.defaultdict(int)

    for source, targets in graph.items():
        degrees[source]
        for target in targets:
            degrees[target] += 1

    return degrees

def topological_sort(graph):
    ''' Perform a topological sort on graph.

    >>> topological_sort(read_graph(io.StringIO('\\n'.join(map(str, SAMPLE_CODES)))))
    [3, 1, 5, 4, 2]

    >>> topological_sort(read_graph(io.StringIO('\\n'.join(map(str, LONGER_CODES)))))
    [2, 1, 9, 8, 0, 4, 3, 5, 7, 6]
    '''

    degrees  = compute_degrees(graph)
    frontier = [v for v, d in degrees.items() if d == 0]
    visited  = []

    while frontier:
        vertex = frontier.pop()
        visited.append(vertex)

        for neighbor in graph[vertex]:
            degrees[neighbor] -= 1
            if degrees[neighbor] == 0:
                frontier.append(neighbor)

    return visited

# Main Execution

def main(stream=sys.stdin):
    ''' Read graph from passcodes, perform topological sort, and print original
    full passcode.

    >>> main(io.StringIO('\\n'.join(map(str, SAMPLE_CODES))))
    31542

    >>> main(io.StringIO('\\n'.join(map(str, LONGER_CODES))))
    2198043576
    '''
    
    while graph := read_graph(stream):
        codes = topological_sort(graph)
        for code in codes:
            print(code, end = '')
        print()

if __name__ == '__main__':
    main()
