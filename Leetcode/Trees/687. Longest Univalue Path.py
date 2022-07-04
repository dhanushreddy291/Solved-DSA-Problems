# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        # Initializing the max Univalue Path as 0
        self.maxUnivaluePath = 0
        # Calling the helper Function which does all the magic by apply Recursion
        self.helper(root)
        # Returning the max Univalue Path
        return self.maxUnivaluePath
        
    def helper(self, root: Optional[TreeNode]) -> int:

        # If root is not a NULL pointer, then only perform the below code
        if root:
            # Applying Recursion and Believing that it just works the way intends to be 🙃
            # Calling the Left and Right Subtrees via Recursion
            LeftPath = self.helper(root.left)
            RightPath = self.helper(root.right)
            L, R = 0, 0

            # 1 is being added to LeftPath or RightPath, becuase if we connect the left subtree to the current node then in that case there is 1 extra edge which is connecting current node to the left subtree, similarily for right subtree
            if root.left and root.left.val == root.val:
                L = 1 + LeftPath
            if root.right and root.right.val == root.val:
                R = 1 + RightPath

            # L + R gives the number of edges when the path goes through the root.
            # L and R are greater than 0 only when the left side and right side corresponding nodes exist and are equal to the current node's values, else they will be zero as initialized at start
            self.maxUnivaluePath = max(self.maxUnivaluePath, L + R)

            # What we are returning is either picking up the left path or right path (whichever has maximum edges as per recursion call)
            return max(L, R)

        # If current node is not a root then return 0
        return 0