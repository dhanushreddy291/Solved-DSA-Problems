# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:

        def Height(root):
            if root is None: 
                return 0
            else: 
                return 1 + max(Height(root.left), Height(root.right))
                
        def CalculateSum(root, depth, currentHeight):
            if root is None:
                return 0
            elif currentHeight == depth:
                return root.val
            else:
                return CalculateSum(root.left, depth, currentHeight + 1) + CalculateSum(root.right, depth, currentHeight + 1)
        
        return CalculateSum(root, Height(root), 1)