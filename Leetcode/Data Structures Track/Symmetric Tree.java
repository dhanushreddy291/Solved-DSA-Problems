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
    public boolean Traverse (TreeNode Root1, TreeNode Root2) {
        if (Root1 == null && Root2 == null) return true;
        else if (Root1 == null || Root2 == null) return false;
        else if (Root1.val == Root2.val && Traverse (Root1.left, Root2.right) && Traverse (Root1.right, Root2.left)) return true;
        else return false;
    }
    public boolean isSymmetric(TreeNode root) {
        return Traverse (root.left, root.right);
    }
}