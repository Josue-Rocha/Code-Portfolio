'''
Title:      priority_queue_tree.py
Abstract:   Implement a priority queue using an array-based binary tree.
Author:     Josue Rocha
Email:      jrocha3@nd.edu
Estimate:   25 minutes
Date:       03/28/2022
Questions:
    1. While performing a BFS, how do you know if node is valid or not?
        if the queue list we are using still has elements
    2. What is the worst-case time complexity of PriorityQueue.pop()?
        O(n)
    3. What is the worst-case space complexity of PriorityQueue.pop()?
        O(log(n))
'''

from collections import deque

# Classes

class PriorityQueue:
    ''' Simple priority queue using an array-based binary tree. '''

    def __init__(self, tree):
        ''' Initialize internal binary tree.
        >>> pq = PriorityQueue([4, 6, 6, 3, 7]); pq.tree
        [4, 6, 6, 3, 7]
        '''
        self.tree = tree if tree else[]


    def pop(self):
        ''' Return the largest value in priority queue.
        Walk tree using BFS to find largest value, place 0 in its place, and
        then return largest value.
        >>> pq = PriorityQueue([4, 6, 6, 3, 7])
        >>> [pq.pop(), pq.pop(), pq.pop(), pq.pop(), pq.pop()]
        [7, 6, 6, 4, 3]
        >>> pq.tree
        [0, 0, 0, 0, 0]
        '''
        queue = []
        queue.append(self.tree[0])
        sz = len(self.tree)
        current = 0
        index = 0
        i = -1

        while len(queue):
          i = i + 1
          node = queue.pop(0)
          if node > current:
            current = node
            index = i

          li = left_child(i)
          ri = right_child(i)

          if li < sz:
            queue.append(self.tree[li])
          if ri < sz:
            queue.append(self.tree[ri])


        self.tree[index] = 0
        return current


# Functions

def left_child(index):
    ''' Return index of left child.
    >>> left_child(0)
    1
    >>> left_child(1)
    3
    '''
    return (2*index) + 1

def right_child(index):
    ''' Return index of right child.
    >>> right_child(0)
    2
    >>> right_child(1)
    4
    '''
    return (2*index) + 2
