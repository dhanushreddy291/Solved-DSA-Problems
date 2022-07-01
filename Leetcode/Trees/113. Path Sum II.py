# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        pathLists = []
        def helper(root, targetSum, currPath, pathLists):
            if root:
                currPath.append(root.val)
                if not root.left and not root.right:
                    if targetSum == root.val:
                        pathLists.append(currPath.copy())
                helper(root.left, targetSum - root.val, currPath, pathLists)
                helper(root.right, targetSum - root.val, currPath, pathLists)
                currPath.pop()
        helper(root, targetSum, [], pathLists)
        return pathLists
        