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
    void Preorder (TreeNode* Root) {
        if (Root) {
            Answer.push_back (Root -> val);
            Preorder (Root -> left);
            Preorder (Root -> right);
        }
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        Preorder (root);
        return Answer;
    }
};