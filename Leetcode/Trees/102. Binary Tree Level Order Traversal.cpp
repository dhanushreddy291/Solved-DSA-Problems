class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int depth = 0;
        vector <vector <int>> Answer;
        while (root) {
            if (root->left) {
                TreeNode* pre = root->left;
                int height = 1;
                while (pre->right && pre->right != root) {
                    height++;
                    pre = pre->right;
                }
                if (pre->right) {
                    pre->right = NULL;
                    depth -= height;
                    Answer[depth - 1].push_back(root->val);
                    root = root->right;
                } else {
                    pre->right = root;
                    root = root->left;
                    depth++;
                }
            } else {
                while (Answer.size() <= depth) {
                    Answer.push_back(vector <int> ());
                }
                Answer[depth].push_back(root->val);
                depth++;
                root = root->right;
            }
        }
        return Answer;
    }
};