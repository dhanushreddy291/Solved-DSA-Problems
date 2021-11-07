/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int pathSum(TreeNode root, int targetSum) {
        if (root == null) return 0;
        else if (root.left == null && root.right == null && root.val == targetSum) return 1;
        else return pathSum(root.left, targetSum - root.val) + pathSum(root.right, targetSum - root.val) + pathSum(root.left, targetSum) + pathSum(root.right, targetSum);
    }
}