class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        # Initialize the Path Sum to a minimum value, say -1000 (-1000 is the least possible value as per question)
        self.PathSum = -1000

        # Call the Helper Function which does the Recursion Magic
        self.helper(root)

        # Return the Max Path Sum
        return self.PathSum

    def helper(self, root):
        if root:
            # Just Believe that Recursion works with a leap of faith and call the left and right subtrees 🙃
            leftSum = self.helper(root.left)
            rightSum = self.helper(root.right)

            # Now consider the path that travels through the current node (root)
            # We are adding the left path sum and right path sum and current root value
            # We are adding the left/right path sums only if they benefit us (they are positive)
            self.PathSum = max(self.PathSum, root.val + max(leftSum, 0) + max(rightSum, 0))

            # Now return the maximum path sum that goes through this root, so either pick which ever is the maximum be it left or right path or None if both are not of any use
            return max(root.val + max(leftSum, 0), root.val + max(rightSum, 0))

        # If current node (root) is Invalid
        return 0
