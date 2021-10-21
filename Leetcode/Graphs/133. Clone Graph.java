class Solution {
    private HashMap <Node, Node> Map = new HashMap<>();
    public Node cloneGraph(Node node) {
        if (node != null) {
            if (Map.containsKey(node)) return Map.get(node);
            Node temp = new Node(node.val);
            Map.put(node, temp);
            for (Node Neighbor : node.neighbors)
                temp.neighbors.add(cloneGraph(Neighbor));
            return temp;
        }
        return node;
    }
}
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/