class Solution {
private:
    vector <vector <int>> Answer;
    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        int maxDepth = max(helper(root -> left), helper(root -> right));
        while (maxDepth + 1 >= Answer.size()) {
            Answer.push_back(vector <int> ());
        }
        Answer[maxDepth].push_back(root -> val);
        return maxDepth;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        helper(root);
        return Answer;  
    }
};