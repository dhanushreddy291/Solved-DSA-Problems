"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
from queue import Queue

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if root:
            Que = Queue()
            Que.put(root)
            Que.put(None)
            while not Que.empty():
                node = Que.get()
                if node:
                    node.next = Que.queue[0]
                    if node.left:
                        Que.put(node.left)
                    if node.right:
                        Que.put(node.right)
                else:
                    if Que.qsize() == 0:
                        break
                    Que.put(None)
        return root
