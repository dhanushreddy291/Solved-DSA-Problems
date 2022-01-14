/*
This is the Node class definition

class Node {
  public:
    int value = 0;
    vector<Node *> neighbors;
    Node(int val) { value = val; }
};
*/
unordered_map <Node*, Node*> Map;
Node *cloneGraph(Node *node) {
    if (node != NULL) {
        Node* clonedNode = new Node(node -> value);
		Map[node] = clonedNode;
        for (auto neighbourNode: node -> neighbors) {
            if (Map.find(neighbourNode) != Map.end())
            clonedNode -> neighbors.push_back(Map[neighbourNode]);
            else clonedNode -> neighbors.push_back(cloneGraph(neighbourNode));
        }
        return clonedNode;
    }
    return node;
}