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