/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    pair <TreeNode*, TreeNode*> FlattenBinaryTree(TreeNode* Root) {
        if (Root == NULL) return {NULL, NULL};
        pair <TreeNode*, TreeNode*> L = FlattenBinaryTree(Root -> left);
        pair <TreeNode*, TreeNode*> R = FlattenBinaryTree(Root -> right);
        Root -> left = NULL;
        if (L.first) {
            Root -> left = NULL;
            Root -> right = L.first;
            L.second -> right = R.first;
            return {Root, R.first == NULL ? L.second : R.second};
        } else {
            Root -> right = R.first;
            return {Root, R.first == NULL ? Root : R.second};
        }
    }
public:
    void flatten(TreeNode* root) {
        FlattenBinaryTree(root);
    }
};