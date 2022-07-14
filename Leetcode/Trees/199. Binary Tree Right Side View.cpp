// Solution using BFS via using a Queue and extra space
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
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
                } else {
                    Answer.push_back(t);
                    if (Queue.empty()) break;
                    t.clear();
                    Queue.push (NULL);  
                }
            }
        }
        int X = Answer.size();
        vector <int> finalAnswer;
        for (int i = 0; i < X; i++) {
            finalAnswer.push_back(Answer[i].back());
        }
        return finalAnswer;
    }
};

// Without using any extra space
class Solution {
private:
    int Height(TreeNode* root) {
        if (root == NULL) return 0; 
        return 1 + max(Height(root -> left), Height(root -> right));
    }
    void inorder(TreeNode* root, int height, vector <int> &Map) {
        if (root) {
            inorder(root -> left, height + 1, Map);
            Map[height] = root -> val;
            inorder(root -> right, height + 1, Map);
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector <int> rightView(Height(root), 0);
        inorder(root, 0, rightView);
        return rightView;
    }
};
