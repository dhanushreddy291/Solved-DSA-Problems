/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null;
        if (root == p || root == q) return root;
        TreeNode LeftLCA = lowestCommonAncestor (root.left, p, q);
        TreeNode RightRCA = lowestCommonAncestor (root.right, p, q);
        if (LeftLCA != null && RightRCA != null) return root;
        else if (LeftLCA != null) return LeftLCA;
        else return RightRCA;
    }
}