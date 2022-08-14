class Solution {
private:
    int leftPos = 0, rightPos = 0;
    void traverse(TreeNode* root, int x) {
        if (root) {
            leftPos = min(x, leftPos);
            rightPos = max(rightPos, x);
            traverse(root -> left, x - 1);
            traverse(root -> right, x + 1);
        }
        return;
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        traverse(root, 0);
        vector <vector <int>> verticalOrder(rightPos - leftPos + 1, vector <int> ());
        if (root) {
            queue <TreeNode*, int> Queue;
            Queue.push({root, 0});
            while (!Queue.empty()) {
                pair <TreeNode*, int> Front = Queue.front();
                Queue.pop();
                verticalOrder[Front.second - leftPos].push_back(Front.first -> val);
                if (Front.first -> left) Queue.push({Front.first -> left, Front.second - 1});
                if (Front.first -> right) Queue.push({Front.first -> right, Front.second + 1});
            }
        }
        return verticalOrder;
    }
};