/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    char K = 'N';
    string ConvertToString (int N, bool isSpaceNeeded = true) {
        bool Negative = false;
        if (N < 0) {
            Negative = true;
            N = abs(N);
        }
        string Answer = "";
        while (N) {
            Answer += (N%10 + '0');
            N /= 10;
        }
        reverse(Answer.begin(), Answer.end());
        string temp = "";
        if (!isSpaceNeeded) temp += ' ';
        if (Negative) temp += '-';
        return temp + Answer;
    }
    void Helper(TreeNode *root, queue <TreeNode*> &Queue, string &SerializedTree) {
        if (root) {
            SerializedTree += ConvertToString(root -> val);
            Queue.push(root -> left);
        } 
        else
        SerializedTree += K;        
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string SerializedTree = "";
        if (root != NULL) {
            queue <TreeNode*> Queue;
            Queue.push(root);
            SerializedTree += ConvertToString(root -> val, false);
            while (!Queue.empty()) {
                if (root) {
                    Helper(root -> left, Queue, SerializedTree);
                    Helper(root -> right, Queue, SerializedTree);
                }
                Queue.pop();
                root = Queue.front();
            }
        }
        return SerializedTree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* Root = NULL;
        if (data.size() == 0) return Root;
        int i = 0;
        while (i < data.size()) {
            int Start = i;
            while (i < data.size() && data[i] != ' ') i++;
            
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));