'''
Title:      tree.py
Abstract:   Implement a binary tree read and walk functions.
Author:     Josue Rocha
Email:      jrocha3@nd.edu
Estimate:   45 minutes
Date:       04/04/2023
Questions:
    1. What is the worst-case time complexity of tree_read()?
        O(n)
    2. What is the worst-case time complexity of tree_walk()?
        O(n)
    3. In tree_walk(), how did you modify BFS to print all the nodes on one
    comma separated line?
        I made a list and used the str.join function with the string ", "
    4. In tree_walk(), how did you remove any trailing invalid nodes from your
    output?
        I made a while loop which pops the end othe list so long as the last number is '0'
'''

from dataclasses import dataclass
from collections import deque

# Classes

@dataclass
class Node:
    value:  str
    left:   'Node' = None
    right:  'Node' = None

# Functions

def tree_read(array, index=0):
    ''' Return a node-based tree from the given array of values in BFS format.
    >>> tree_read([1, 2, 3])
    Node(value=1, left=Node(value=2, left=None, right=None), right=Node(value=3, left=None, right=None))
    >>> tree_read([1, 2, 3, 4, 0, 0, 6])
    Node(value=1, left=Node(value=2, left=Node(value=4, left=None, right=None), right=None), right=Node(value=3, left=None, right=Node(value=6, left=None, right=None)))
    '''
    if index >= len(array) or not array[index]:
        return None

    # Divide and Conquer and Combine
    return Node(
        value = array[index],
        left  = tree_read(array, 2*index + 1),
        right = tree_read(array, 2*index + 2),
    )

def tree_walk(root):
    ''' Print out the tree in level-by-level order with each level on the same
    line.
    >>> tree_walk(tree_read([1, 2, 3]))
    1, 2, 3
    >>> tree_walk(tree_read([1, 2, 3, 4, 0, 0, 6]))
    1, 2, 3, 4, 0, 0, 6
    '''
    my_list = []
    queue = deque([root])
    level = 0
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
    #print(my_list)
    print(my_str)
