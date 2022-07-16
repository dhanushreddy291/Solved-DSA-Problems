# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def helper(p1, p2, i1, i2):
            if i1 > i2:
                return None
            index = inorder.index(preorder[p1])
            return TreeNode(
                preorder[p1],
                helper(p1 + 1, p1 + index - i1, i1, index - 1),
                helper(p1 + 1 + index - i1, p2, index + 1, i2),
            )

        return helper(0, len(preorder) - 1, 0, len(inorder) - 1)
