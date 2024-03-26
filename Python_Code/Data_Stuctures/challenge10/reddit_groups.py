#!/usr/bin/env python3

'''
Title:      reddit_groups.py
Abstract:   Determine how many isolated groups are in graph.
Author:     Josue Rocha
Email:      jrocha3@nd.edu
Estimate:   30 minutes
Date:       04/27/2023
Questions:

    1. Does it make a difference if you used BFS or DFS for walk_graph?
    Explain.
        In terms of the output, no beccuase it will not affect the set we are creating. However, depending on how your are using a queue for BFS, it may increase the time complexity if you use pop(0) becuase, then python has to create a new list and transfer over the information.

    2. What is the average time complexity of walk_graph?

        O(n)

    3. What is the average time complexity of find_groups?
        
        O(n)
'''

import io
import sys

# Functions

def read_graph(stream=sys.stdin):
    ''' Read one graph from the stream.

    >>> read_graph(io.StringIO('4\\n3\\n1 2\\n2 3\\n4 1\\n'))
    {1: [2, 4], 2: [1, 3], 3: [2], 4: [1]}

    >>> read_graph(io.StringIO('4\\n2\\n1 2\\n3 4\\n'))
    {1: [2], 2: [1], 3: [4], 4: [3]}
    '''

    d = dict()

    try:
        n = int(stream.readline())
        m = int(stream.readline())
    except ValueError:
        return None

    for i in range(1, n+1):
        d[i] = []


    for i in range(m):
        n1, n2 = stream.readline().split()
        n1 = int(n1)
        n2 = int(n2)

        d[n1].append(n2)
        d[n2].append(n1)

    return d

def walk_graph(graph, origin):
    ''' Perform traversal of graph from origin.

    >>> g = read_graph(io.StringIO('4\\n3\\n1 2\\n2 3\\n4 1\\n'))
    >>> walk_graph(g, 1)
    {1, 2, 3, 4}

    >>> g = read_graph(io.StringIO('4\\n2\\n1 2\\n3 4\\n'))
    >>> walk_graph(g, 1)
    {1, 2}
    '''

    frontier = [origin]
    visited = set()

    while frontier:
        vertex = frontier.pop()

        if vertex in visited: continue

        visited.add(vertex)

        for neighbor in graph[vertex]:
            frontier.append(neighbor)
    
    return visited

def find_groups(graph):
    ''' Find isolated groups in graph.

    >>> g = read_graph(io.StringIO('4\\n3\\n1 2\\n2 3\\n4 1\\n'))
    >>> find_groups(g)
    [[1, 2, 3, 4]]

    >>> g = read_graph(io.StringIO('4\\n2\\n1 2\\n3 4\\n'))
    >>> find_groups(g)
    [[1, 2], [3, 4]]
    '''

    groups = []
    visited = set()

    for item in graph:

        if item in visited:
            continue

        visited.add(item)

        group = list(walk_graph(graph, item))

        for num in group:
            visited.add(num)

        groups.append(group)

    return groups

# Main Execution

def main(stream=sys.stdin):
    ''' For each graph, find the number of isolated graphs, and print them out
    in sorted order.

    >>> main(io.StringIO('4\\n3\\n1 2\\n2 3\\n4 1\\n4\\n2\\n1 2\\n3 4\\n10\\n8\\n1 2\\n6 8\\n8 1\\n10 6\\n7 7\\n7 5\\n3 6\\n6 2\\n'))
    Graph 1:
    1 2 3 4
    Graph 2:
    1 2
    3 4
    Graph 3:
    1 2 3 6 8 10
    4
    5 7
    9
    '''

    n = 1
    while graph := read_graph(stream):
        groups = find_groups(graph)
        print(f'Graph {n}:')

        for group in groups:
            for i, num in enumerate(group, 1):
                if i == len(group):
                    print(num)
                else:
                    print(f'{num} ', end='')
        n += 1

if __name__ == '__main__':
    main()
