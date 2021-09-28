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
public:
    vector <int> Answer;
    void Inorder (TreeNode* Root) {
        if (Root) {
            Inorder (Root -> left);
            Answer.push_back (Root -> val);
            Inorder (Root -> right);
        }
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        Inorder (root);
        return Answer;
    }
};