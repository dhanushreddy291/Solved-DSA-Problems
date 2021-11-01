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
    public int sumEvenGrandparent(TreeNode root) {
        int Sum = 0;
        if (root == null) return 0;
        if (root.val % 2 == 0) {
            if (root.left != null) {
                if (root.left.left != null) Sum += root.left.left.val;
                if (root.left.right != null) Sum += root.left.right.val;
            }
            if (root.right != null) {
                if (root.right.left != null) Sum += root.right.left.val;
                if (root.right.right != null) Sum += root.right.right.val;
            }
        }
        return Sum + sumEvenGrandparent(root.left) + sumEvenGrandparent(root.right);
    }
}