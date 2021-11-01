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
    public int deepestLeavesSum(TreeNode root) {
        int depth = Depth(root), currentHeight = 1;
        return CalculateSum(root, depth, currentHeight);
    }
    private int Depth(TreeNode Root) {
        if (Root == null) return 0;
        else return 1 + Math.max(Depth(Root.left), Depth(Root.right));
    }
    private int CalculateSum(TreeNode root, int depth, int currentHeight) {
        if (root == null) return 0;
        else if (currentHeight == depth) return root.val;
        else return CalculateSum(root.left, depth, currentHeight + 1) + CalculateSum(root.right, depth, currentHeight + 1);
    }
}