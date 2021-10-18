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
    map <int, vector <TreeNode*>> Cache;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n%2 == 0) return {};
        else if (n == 1) return {new TreeNode(0)};
        else if (Cache.find(n) != Cache.end()) return Cache[n];
        else {
            vector <TreeNode*> Answer;
            for (int i = 1; i < n; i += 2) {
                vector <TreeNode*> Left = allPossibleFBT(i), Right = allPossibleFBT(n - i - 1);
                for (int j = 0; j < Left.size(); j++) {
                    for (int k = 0; k < Right.size(); k++) {
                        Answer.push_back(new TreeNode(0, Left[j], Right[k]));
                    }
                }
            }
            return Cache[n] = Answer;
        }  
    }
};