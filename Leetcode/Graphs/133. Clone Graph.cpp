class Solution {
private:
    unordered_map <Node*, Node*> Map;
public:
    Node* cloneGraph(Node* node) {
        if (node) {
            if (Map.find(node) != Map.end()) return Map[node];
            Map[node] = new Node(node -> val);
            for (Node* Neighbor : node -> neighbors) 
                Map[node] -> neighbors.push_back(cloneGraph(Neighbor));
            return Map[node];
        }
        return node;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/