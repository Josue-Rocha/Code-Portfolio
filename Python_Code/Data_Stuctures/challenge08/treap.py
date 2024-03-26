'''
Title:      treap.py
Abstract:   Implement a Map class using a treap.
Author:     Domer McDomerson
Email:      dmcdomer@nd.edu
Estimate:   30 minutes
Date:       04/18/2023
Questions:
    1. What is worst-case time complexity of Map.insert()?
        O(n)
    2. What is worst-case time complexity of Map.search()?
        O(n)
    3. What role does a Node's priority play during insertion?
        determines whether or not you swap, and how you swap
    4. How did you use a dictionary in Map._dump_tree() to help you print each
    level on a single line?
        each key in the dictionary is the level and the value is a list of the values for the Nodes in that level
'''

from collections import deque, defaultdict
from dataclasses import dataclass
import random

# Classes

@dataclass
class Node:
    ''' Node with string key, int value, float priority, and left and right children. '''
    key:        str
    value:      int    = None
    priority:   float  = None
    left:       'Node' = None
    right:      'Node' = None

class Map:
    ''' Map Implementation based on a treap. '''

    def __init__(self):
        ''' Initialize empty Map.
        >>> m = Map(); not m.root
        True
        '''
        self.root = None

    def insert(self, key, value, priority=None):
        ''' Insert key, value pair into Map.  If key is already in Map, then
        update value.
        >>> m = Map()
        >>> m.insert('D', 0, 60); m.root
        Node(key='D', value=0, priority=60, left=None, right=None)
        >>> m.insert('F', 1, 76); m.root.key        # Rotate Left
        'F'
        >>> m.insert('H', 2, 14); m.root.right.key
        'H'
        >>> m.insert('C', 3, 70); m.root.left.key   # Rotate Right
        'C'
        >>> m.insert('A', 4, 55); m.root.left.left.key
        'A'
        '''
        if not priority:
            priority = random.randint(0, 100)
        self.root = self._insert(self.root, key, value, priority)

    def _insert(self, node, key, value, priority=None):
        ''' Recursively insert key, value pair into Map. '''
        if node is None: # empty treap
            tree = Node(key=key, value=value, priority=priority, left=None, right=None) # create root with the values provided (also our base case)
            return tree
        if key < node.key: #BST property
            node.left = self._insert(node.left, key, value, priority) # recursive case
            if node.left.priority > node.priority:
                node = self._rotate_right(node) # rotate right
        elif key > node.key: #BST property
            node.right = self._insert(node.right, key, value, priority) # recursive case
            if node.right.priority > node.priority:
                node = self._rotate_left(node) # rotate left
        else:
          node.value = value # update value if node is already there
        return node

    def lookup(self, key):
        ''' Lookup key in Map and return associated value (None if missing).
        >>> m = Map()
        >>> d = [('sbn', '574'), ('eau', '715'), ('sna', 714), ('nyc', 646)]
        >>> for k, v in d: m.insert(k, v)
        >>> all(m.lookup(k) == v for k, v in d)
        True
        >>> m.lookup('stl')
        '''
        return self._lookup(self.root, key)

    def _lookup(self, node, key):
        ''' Recursively lookup key in Map and return associated value (None if
        missing). '''
        if node is None: # base case
            return None
        elif node.key == key: # found it!
            return node.value
        elif key < node.key:
            return self._lookup(node.left, key) # recursive case
        else:
            return self._lookup(node.right, key) # recursive case

    @staticmethod
    def _dump_tree(root):
        ''' Output tree keys in BFS (level-by-level) order.
        - Print out one level per line (with nodes separated by spaces).
        - Do not print any lines with only invalid nodes.
        >>> tree = Node('A', left=Node('B'), right=Node('C'))
        >>> Map._dump_tree(tree)
        A
        B C
        >>> tree = Node('A', left=Node('B', left=Node('C'), right=Node('D')), right=Node('E'))
        >>> Map._dump_tree(tree)
        A
        B E
        C D 0 0
        >>> tree = Node('A', left=Node('B'), right=Node('C', left=Node('D'), right=Node('E')))
        >>> Map._dump_tree(tree)
        A
        B C
        0 0 D E
        '''
        level = 0
        queue = deque([root])

        def def_value():
          return 0
        d = defaultdict(def_value)

        while queue:
          size = len(queue)
          my_list = [] # the list will contain all the nodes for the level it is on
          for i in range(size):

            node = queue.popleft()
            if node == '0':
              my_list.append('0')
              continue

            my_list.append(node.key)

            if node.left:
                queue.append(node.left)
            else:
              queue.append('0') # include zeros to print complete tree

            if node.right:
                queue.append(node.right)
            else:
              queue.append('0') # include zeros to print complete tree

          d[level] = my_list # add level : list_of_nodes as key value pair to dict d
          level += 1 # update level

        d.popitem()
        for item in d.items():
          sz = len(item[1])
          for i in range(sz):
            if i < sz -1:
             print(f'{item[1][i]} ', end ='')
            else:
              print(f'{item[1][i]}', end ='')
          print()


    @staticmethod
    def _rotate_right(p):
        ''' Rotate the sub-tree at parent node to the right.
            P               CL
           / \             /  \
          CL CR     =>    GL   P
         /  \                 / \
        GL  GR              GR   CR
        >>> tree = Node('A', left=Node('B'), right=Node('C'))
        >>> Map._dump_tree(Map._rotate_right(tree))
        B
        0 A
        0 C
        >>> tree = Node('A', left=Node('B', left=Node('C'), right=Node('D')), right=Node('E'))
        >>> Map._dump_tree(Map._rotate_right(tree))
        B
        C A
        0 0 D E
        '''
        left = p.left
        p.left = left.right
        left.right = p
        return left

    @staticmethod
    def _rotate_left(p):
        ''' Rotate the sub-tree at parent node to the left.
            P               CR
           / \             /  \
          CL CR     =>    P   GR
            /  \         / \
           GL  GR       CL  GL
        >>> tree = Node('A', left=Node('B'), right=Node('C'))
        >>> Map._dump_tree(Map._rotate_left(tree))
        C
        A 0
        B 0
        >>> tree = Node('A', left=Node('B'), right=Node('C', left=Node('D'), right=Node('E')))
        >>> Map._dump_tree(Map._rotate_left(tree))
        C
        A E
        B D 0 0
        '''
        right = p.right
        p.right = right.left
        right.left = p
        return right
