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
    public boolean isUnivalTree(TreeNode root) {
        int Val = root.val;
        return isTreeUnivalued(root, Val);
    }
    private boolean isTreeUnivalued(TreeNode root, int val) {
        if (root == null) return true;
        else if ((root.left != null && root.left.val != val) || (root.right != null && root.right.val != val)) return false;
        else return isTreeUnivalued(root.left, val) && isTreeUnivalued(root.right, val);
    }
}