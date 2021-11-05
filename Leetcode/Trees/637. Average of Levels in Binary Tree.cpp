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
    vector<double> averageOfLevels(TreeNode* root) {
        queue <TreeNode*> Queue;
        vector <int> t;
        vector <vector <int>> Answer;
        if (root) {
            Queue.push (root);
            Queue.push (NULL);
            while (!Queue.empty()) {
                TreeNode* Top = Queue.front();
                Queue.pop ();
                if (Top) {
                    if (Top -> left) Queue.push (Top -> left);
                    if (Top -> right) Queue.push (Top -> right);
                    t.push_back (Top -> val);
                } 
                else {
                    Answer.push_back(t);
                    if (Queue.empty()) break;
                    t.clear();
                    Queue.push (NULL);  
                }
            }
        }
        vector <double> finalAnswer;
        int X = Answer.size();
        for (int i = 0; i < X; i++) {
            int Y = Answer[i].size();
            double Sum = 0;
            for (int j = 0; j < Y; j++) Sum += Answer[i][j];
            finalAnswer.push_back(Sum / Y);
        }
        return finalAnswer;
    }    
};