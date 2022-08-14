class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int level = 1, maxSum = INT_MIN, currLevel = 1;
        queue <TreeNode*> Queue;
        Queue.push(root);
        while (!Queue.empty()) {
            int size = Queue.size(), currSum = 0;
            while (size--) {
                currSum += Queue.front() -> val;
                if (Queue.front() -> left) Queue.push(Queue.front() -> left);
                if (Queue.front() -> right) Queue.push(Queue.front() -> right);
                Queue.pop();
            }
            if (maxSum < currSum) {
                maxSum = currSum;
                level = currLevel;
            }
            currSum = 0;
            currLevel++;
        }
        return level;
    }
};