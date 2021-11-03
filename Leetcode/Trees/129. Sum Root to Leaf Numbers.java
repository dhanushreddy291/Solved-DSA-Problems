class Solution {
    public int sumNumbers(TreeNode root) {
        return Helper(root, 0);
    }
    //currentSum variable at any given time contains the number from root to that node for every recursive call.
    private int Helper(TreeNode root, int currentSum) {
        //Base Case for a null ptr
        if (root == null) return 0;
        //If the node is leave then return the Number that is generated from root to this node
        if (root.left == null && root.right == null) return 10 * currentSum + root.val;
        //Continue the DFS
        return Helper(root.left, 10 * currentSum + root.val) + Helper(root.right, 10 * currentSum + root.val);
    }
}