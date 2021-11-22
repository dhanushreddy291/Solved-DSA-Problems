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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root != null) {

            //When the Left SubTree Contains the Key
            if (root.val > key) root.left = deleteNode(root.left, key);

            //When the Right SubTree Contains the Key
            else if (root.val < key) root.right = deleteNode(root.right, key);

            //When the Root is the Key
            else {

                //When there is no Left SubTree, return the Right SubTree
                if (root.left == null) return root.right;
                else if (root.right == null) return root.left;

                else {

                    //When there is no Left SubTree, return the Right SubTree
                    if (root.left == null) return root.right;

                    //When there is no Right SubTree, return the Left SubTree
                    else if (root.right == null) return root.left;

                    //When left and right nodes are present attach one to other like attaching LeftSubTree to RightSubTree's LeftMost Node's left joint or attaching RightSubTree to LeftSubTree's RightMost Node's Right joint
                    else {
                        TreeNode R = root.right, Prev = null;
                        while (R != null) {
                            Prev = R;
                            R = R.left;
                        }
                        Prev.left = root.left;
                        return root.right;
                    }
                }
            }
        }

        //Return the root
        return root;
    }
}