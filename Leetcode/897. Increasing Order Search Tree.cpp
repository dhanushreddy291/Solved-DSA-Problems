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
    pair <TreeNode*, TreeNode*> Helper(TreeNode* Root) {
        if (Root == NULL) return {NULL, NULL};
        pair <TreeNode*, TreeNode*> L, R;
        if (Root -> left == NULL) {
            R = Helper(Root -> right);
            Root -> right = R.first;
            return {Root, R.second == NULL ? Root : R.second};
        }
        else {
            L = Helper(Root -> left);
            L.second -> right = Root;
            R = Helper(Root -> right);
            Root -> left = NULL;
            Root -> right = R.first;
            return {L.first, R.first == NULL ? Root : R.second};
        }
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        return Helper(root).first;
    }
};