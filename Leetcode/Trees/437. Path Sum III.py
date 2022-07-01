class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        def helper(root, targetSum):
            if root:
                count = 0
                if targetSum == root.val:
                    count += 1
                return count + helper(root.left, targetSum - root.val) + helper(root.right, targetSum - root.val)
            return 0
        L, R = 0, 0
        if root:
            if root.left:
                L = self.pathSum(root.left, targetSum)
            if root.right:
                R = self.pathSum(root.right, targetSum)
        return helper(root, targetSum) + L + R
