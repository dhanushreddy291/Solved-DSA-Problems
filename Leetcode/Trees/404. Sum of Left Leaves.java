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
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) return 0;
        int Sum = 0;
        if (root.left != null) {
            if (root.left.left == null && root.left.right == null) Sum += root.left.val;
        }
        Sum += sumOfLeftLeaves (root.left) + sumOfLeftLeaves (root.right);
        return Sum;
    }
}