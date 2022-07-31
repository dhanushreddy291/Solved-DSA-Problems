class Solution {
    private boolean BSTValid;
    private int[] isBSTValid(TreeNode root) {
        if (!BSTValid) return new int[]{Integer.MIN_VALUE, Integer.MAX_VALUE};
        if (root.left == null && root.right == null) {
            return new int[]{root.val, root.val};
        }
        int[] L = new int[]{root.val, root.val};
        int[] R = new int[]{root.val, root.val};
        if (root.left != null && root.right == null) {
            L = isBSTValid(root.left);
            if (L[1] >= root.val) {
                BSTValid = false;
            }
            return new int[]{L[0], root.val};
        }
        if (!BSTValid) return new int[]{Integer.MIN_VALUE, Integer.MAX_VALUE};
        if (root.right != null && root.left == null ) {
            R = isBSTValid(root.right);
            if (R[0] <= root.val) {
                BSTValid = false;
            }
            return new int[]{root.val, R[1]};
        }
        if (!BSTValid) return new int[]{Integer.MIN_VALUE, Integer.MAX_VALUE};
        L = isBSTValid(root.left);
        R = isBSTValid(root.right);
        if (L[1] >= root.val || R[0] <= root.val) {
            BSTValid = false;
        }
        return new int[]{L[0], R[1]};
    }
    public boolean isValidBST(TreeNode root) {
        BSTValid = true;
        isBSTValid(root);
        return BSTValid;
    }
}