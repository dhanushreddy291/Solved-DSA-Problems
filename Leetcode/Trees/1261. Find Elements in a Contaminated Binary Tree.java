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
class FindElements {

    HashSet <Integer> Set;

    public FindElements(TreeNode root) {
        Set = new HashSet<>();
        recoverTree(root, 0);
    }

    public boolean find(int target) {
        return Set.contains(target);
    }

    private void recoverTree(TreeNode root, int Val) {
        if (root == null) return;
        Set.add(Val);
        recoverTree(root.left, 2 * Val + 1);
        recoverTree(root.right, 2 * Val + 2);
    }
    
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */