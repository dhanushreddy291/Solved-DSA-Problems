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
    TreeNode Search (TreeNode A, int B) {
        if (A == null) return A;
        if (A.val >= B) {
            if (A.left == null) return A;
            return Search (A.left, B);
        } else {
            if (A.right == null) return A;
            return Search (A.right, B);
        }
    }
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        TreeNode L = Search (root, val);
        if (L.val < val) L.right = new TreeNode(val);
        else L.left = new TreeNode(val);
        return root;
    }
}