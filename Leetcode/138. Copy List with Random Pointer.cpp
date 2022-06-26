/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head) {
            unordered_map <Node*, Node*> Map;
            Node* root = head -> next, *copyList = new Node(head -> val), *copyRoot = copyList;
            Map[head] = copyList;
            while (root) {
                copyRoot -> next = new Node(root -> val);
                copyRoot = copyRoot -> next;
                Map[root] = copyRoot;
                root = root -> next;
            }
            root = head;
            while (root) {
                if (root -> random) {
                    Map[root] -> random = Map[root -> random];
                }
                root = root -> next;
            }
            return copyList;
        }
        return NULL;
    }
};