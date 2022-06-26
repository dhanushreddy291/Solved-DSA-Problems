# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def inorder(root, traversedList):
            if not root:
                return
            inorder(root.left, traversedList)
            traversedList.append(root.val)
            inorder(root.right, traversedList)
        traversedList = []
        inorder(root, traversedList)
        return traversedList
        