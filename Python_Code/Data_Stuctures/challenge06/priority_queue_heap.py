'''
Title:      priority_queue_heap.py
Abstract:   Implement a priority queue using a binary heap.
Author:     Josue Rocha
Email:      jrocha3@nd.edu
Estimate:   1 hour
Date:       03/30/2023
Questions:
    1. What is the worst-case time complexity of PriorityQueue.push()?
        O(log(n))
    2. What is the worst-case time complexity of PriorityQueue.pop()?
        O(n)
    3. How did you work around the fact that heapq is a min-heap, while our
    PriorityQueue is a max-heap?
        I convereted all of the elements in the heap to the negative version of themselves
'''

import heapq

# Classes

class PriorityQueue:
    ''' Simple priority queue based on a binary heap. '''

    def __init__(self, data=None):
        ''' Initialize the internal data.
        >>> pq = PriorityQueue(); pq.data
        []
        >>> pq = PriorityQueue([3, 1, 4]); pq.data[0]
        -4
        '''
        if data:
            for i in range(len(data)):
                data[i] = -data[i]
            heapq.heapify(data)
            self.data = data
        else:
            self.data = []

    def push(self, item):
        ''' Add item to Priority Queue.
        >>> pq = PriorityQueue(); pq.push(3); pq.data[0]
        -3
        >>> pq.push(1); pq.data[0]
        -3
        >>> pq.push(4); pq.data[0]
        -4
        '''
        heapq.heappush(self.data, -item)

    def pop(self):
        ''' Remove and return smallest value from the Priority Queue.
        >>> pq = PriorityQueue([3, 1 ,4]); pq.pop()
        4
        >>> pq.pop()
        3
        >>> pq.pop()
        1
        '''
        return -heapq.heappop(self.data)

    def size(self):
        ''' Return number of values in Priority Queue.
        >>> pq = PriorityQueue(); pq.size()
        0
        >>> pq = PriorityQueue([3, 1, 4]); pq.size()
        3
        '''
        return len(self.data)
