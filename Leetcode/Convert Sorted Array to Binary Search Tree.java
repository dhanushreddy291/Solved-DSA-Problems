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
    public TreeNode makeTree (int[] nums, int start, int end) {
        if (start > end) return null;
        int mid = start + (end - start) / 2;
        return new TreeNode (nums[mid], makeTree (nums, start, mid - 1), makeTree (nums, mid + 1, end));
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        return makeTree (nums, 0, nums.length - 1);
    }
}