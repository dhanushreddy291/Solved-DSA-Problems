/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root) {
            queue <Node*> Queue;
            Queue.push (root);
            Queue.push (NULL);
            while (!Queue.empty()) {
                Node* K = Queue.front();
                Queue.pop();
                if (K) {
                    K -> next = Queue.front();
                    if (K -> left) Queue.push (K -> left);
                    if (K -> right) Queue.push (K -> right);
                }
                else {
                    if (Queue.empty()) break;
                    else Queue.push (NULL);
                }
            }
        }
        return root;
    }
};