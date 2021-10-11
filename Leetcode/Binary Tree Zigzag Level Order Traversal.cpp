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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int>> Answer;
        vector <int> temp;
        queue <TreeNode*> Queue;
        if (root) {
            Queue.push (root);
            Queue.push (NULL);
            while (!Queue.empty()) {
                TreeNode* k = Queue.front();
                Queue.pop();
                if (k) {
                    if (k -> left) Queue.push (k -> left);
                    if (k -> right) Queue.push (k -> right);
                    temp.push_back (k -> val);
                } else {
                    Answer.push_back (k);
                    if (Queue.empty ()) break;
                    temp.clear ();
                    Queue.push (NULL);
                }
            }            
        }
        for (int i = 1; i < Answer.size(); i += 2) 
            reverse (Answer[i].begin(), Answer[i].end());
        return Answer;
    }
};