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
    void Postorder (TreeNode* Root) {
        if (Root) {
            Postorder (Root -> left);
            Postorder (Root -> right);
            Answer.push_back (Root -> val);
        }
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        Postorder (root);
        return Answer;
    }
};