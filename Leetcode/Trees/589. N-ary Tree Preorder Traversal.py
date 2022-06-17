"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:

        def traverse(root, traversal):
            if root:
                traversal.append(root.val)
                for child in root.children:
                    traverse(child, traversal)
            else:
                return

        preorderTraversal = []
        traverse(root, preorderTraversal)
        return preorderTraversal
