#!/usr/bin/env python3

'''
Title:      sim_city.py
Abstract:   Compute the minimum spanning tree of points in a city map.
Author:     Josue Rocha
Email:      jrocha3@nd.edu
Estimate:   30 minutes
Date:       05/12/2023
Questions:

    1. What is the average time complexity of build_graph?

        O(n^2), n is the number of points

    2. What is the average time complexity of compute_mst?

        O(V+ElogE), V = # Vertices, E = # of Edges

    3. What is the average space complexity of compute_mst?

        O(V+E), V = # of Vertices, E = # of edges

    4. Does the total cost of the minimum spanning tree change if we use
    different starting vertices isfor compute_mst?  Experiment and then
    explain.

        ????
'''

import collections
import heapq
import io
import math
import requests
import sys

from collections import defaultdict

# Constants

POINTS_URL  = 'https://yld.me/raw/jpIx'
POINTS_TEXT = requests.get(POINTS_URL).text

# Read Points

def read_points(stream=sys.stdin):
    ''' Read points from stream.

    >>> points_stream = io.StringIO(POINTS_TEXT)

    >>> read_points(points_stream)
    [(0, 1.0, 1.0), (1, 2.0, 2.0), (2, 2.0, 4.0)]

    >>> read_points(points_stream)
    [(0, 1.0, 1.0), (1, 2.0, 2.0), (2, 1.0, 2.0), (3, 2.0, 1.0)]

    >>> read_points(points_stream)
    [(0, 0.0, 1.0), (1, 2.0, 3.0), (2, 4.0, 1.0), (3, 1.0, 2.0), (4, 5.0, 2.0)]
    '''

    try:
        n = int(stream.readline())
    except ValueError:
        return None

    points = []
    for i in range(n):
        n1, n2 = stream.readline().split()


        n1 = float(n1)
        n2 = float(n2)
        point = (i, n1, n2)

        points.append(point)

    return points

def build_graph(points):
    ''' Build adjacency list from list of points.

    >>> points_stream = io.StringIO(POINTS_TEXT)

    >>> build_graph(read_points(points_stream))
    defaultdict(<class 'dict'>, {0: {0: 0.0, 1: 1.4142135623730951, 2: 3.1622776601683795}, 1: {0: 1.4142135623730951, 1: 0.0, 2: 2.0}, 2: {0: 3.1622776601683795, 1: 2.0, 2: 0.0}})

    >>> build_graph(read_points(points_stream))
    defaultdict(<class 'dict'>, {0: {0: 0.0, 1: 1.4142135623730951, 2: 1.0, 3: 1.0}, 1: {0: 1.4142135623730951, 1: 0.0, 2: 1.0, 3: 1.0}, 2: {0: 1.0, 1: 1.0, 2: 0.0, 3: 1.4142135623730951}, 3: {0: 1.0, 1: 1.0, 2: 1.4142135623730951, 3: 0.0}})

    >>> build_graph(read_points(points_stream))
    defaultdict(<class 'dict'>, {0: {0: 0.0, 1: 2.8284271247461903, 2: 4.0, 3: 1.4142135623730951, 4: 5.0990195135927845}, 1: {0: 2.8284271247461903, 1: 0.0, 2: 2.8284271247461903, 3: 1.4142135623730951, 4: 3.1622776601683795}, 2: {0: 4.0, 1: 2.8284271247461903, 2: 0.0, 3: 3.1622776601683795, 4: 1.4142135623730951}, 3: {0: 1.4142135623730951, 1: 1.4142135623730951, 2: 3.1622776601683795, 3: 0.0, 4: 4.0}, 4: {0: 5.0990195135927845, 1: 3.1622776601683795, 2: 1.4142135623730951, 3: 4.0, 4: 0.0}})
    '''
    graph = defaultdict(dict)

    for point in points:
        p1 = point[0]
        x1 = point[1]
        y1 = point[2]
        edges = dict()
        for d in points:
            p2 = d[0]
            x2 = d[1]
            y2 = d[2]

            x = abs(x2 - x1)
            y = abs(y2 - y1)

            x = x**2
            y = y**2

            value = math.sqrt(x + y)
            edges[p2] = value

        graph[p1] = edges
    return graph

# Compute MST
def compute_mst(graph, start):
    ''' Compute minimum spanning tree.

    >>> points_stream = io.StringIO(POINTS_TEXT)

    >>> graph = build_graph(read_points(points_stream))
    >>> compute_mst(graph, min(graph))
    {0: 0, 1: 0, 2: 1}

    >>> graph = build_graph(read_points(points_stream))
    >>> compute_mst(graph, min(graph))
    {0: 0, 2: 0, 1: 2, 3: 0}

    >>> graph = build_graph(read_points(points_stream))
    >>> compute_mst(graph, min(graph))
    {0: 0, 3: 0, 1: 3, 2: 1, 4: 2}
    '''

    frontier = [(0, start, start)]
    visited = {}

    while frontier:
        weight, target, source = heapq.heappop(frontier)

        if target in visited: 
            continue

        visited[target] = source

        for neighbor, weight in graph[target].items():
            heapq.heappush(frontier, (weight, neighbor, target))
    
    return visited

# Main Execution

def main(stream=sys.stdin):
    ''' For each set of points, build the graph, compute the MST, and then
    print out the total cost.

    >>> main(io.StringIO(POINTS_TEXT))
    Graph 1: 3.41
    Graph 2: 3.00
    Graph 3: 7.07
    Graph 4: 12.73
    Graph 5: 27.08
    '''
    i = 1
    while group := read_points(stream):
        graph = build_graph(group)
        mst = compute_mst(graph, min(graph))
        total = 0
        for k,v in mst.items():
            total += graph[k][v]
        print(f'Graph {i}: {total:.2f}')
        i += 1

if __name__ == '__main__':
    main()
