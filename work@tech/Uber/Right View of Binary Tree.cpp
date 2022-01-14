/* This is the Node class definition

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
*/

vector < int > rightView(Node * root) {

    deque < Node * > Deque;
    Deque.push_back(root);
    Deque.push_back(NULL);
    vector < int > Answer;
    Node * C;
    bool RightMostElement = true;

    while (!Deque.empty()) {

        C = Deque.front();
        Deque.pop_front();

        if (C == NULL) {
            if (Deque.empty()) break;
            else {
                Deque.push_back(NULL);
                RightMostElement = true;
            }
        } else {
            if (RightMostElement) {
                Answer.push_back(C -> val);
                RightMostElement = false;
            }
            if (C -> right) Deque.push_back(C -> right);
            if (C -> left) Deque.push_back(C -> left);
        }
    }

    return Answer;
}