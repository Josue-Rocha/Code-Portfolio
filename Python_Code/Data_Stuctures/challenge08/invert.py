'''
Title:      invert.py
Abstract:   Invert binary tree.
Author:     Josue Rocha
Email:      jrocha3@nd.edu
Estimate:   45 minutes
Date:       04/18/2023
Questions:
    1. What is the worst-case time complexity of tree_invert()?
        O(nlongn)
    2. How do you swap two values in Python without a temporary value?
        you take advantage of how python lets you return two things at once
'''

import sys
from dataclasses import dataclass
from collections import deque

@dataclass
class Node:
    value:  str
    left:   'Node' = None
    right:  'Node' = None

# Functions

def tree_read(array, index=0):
    if index >= len(array) or not array[index]:
        return None

    # Divide and Conquer and Combine
    return Node(
        value = array[index],
        left  = tree_read(array, 2*index + 1),
        right = tree_read(array, 2*index + 2),
    )

def tree_walk(root):
    my_list = []
    queue = deque([root])
    while queue:
        node = queue.popleft()
        if node == '0':
            my_list.append('0')
            continue
        my_list.append(str(node.value)) 

        if node.left:
            queue.append(node.left)
        else:
            queue.append('0')

        if node.right: 
            queue.append(node.right)
        else:
            queue.append('0')


    while(my_list[-1] == '0'):
        my_list.pop()


    my_str = ', '.join(my_list)
    print(my_str)
def tree_invert(node):
    ''' Invert tree in-place using divide and conquere.
    >>> tree_walk(tree_invert(tree_read([1, 2, 3])))
    1, 3, 2
    >>> tree_walk(tree_invert(tree_read([1, 2, 3, 4, 0, 0, 6])))
    1, 3, 2, 6, 0, 0, 4
    '''
    if node is None: # base case
      return None;

    node.left, node.right = node.right, node.left # swap cause python is cool like that :)

    tree_invert(node.left) # recursive case
    tree_invert(node.right) # recursive case

    return node
# Main Execution

def main(stream=sys.stdin):
    ''' For each line, read in the tree in BFS format, print it, invert it, and
    then print it again.
    >>> import io
    >>> main(io.StringIO('1 2 3\\n1 2 3 4 0 0 6\\n'))
    1, 2, 3
    1, 3, 2
    1, 2, 3, 4, 0, 0, 6
    1, 3, 2, 6, 0, 0, 4
    '''
    
    # parse arguments in stream
    for item in stream:
        item = item.strip()
        item = item.split()

        tree_walk(tree_read(item))
        tree_walk(tree_invert(tree_read(item)))


if __name__ == '__main__':
    main()

