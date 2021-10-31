/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List <Integer> Answer = new ArrayList<>();
    public List<Integer> preorder(Node root) {
        if (root == null) return Answer;
        PreorderTraverser(root);
        return Answer;
    }
    private void PreorderTraverser(Node root) {
        if (root == null) return;
        Answer.add(root.val);
        if (root.children == null) return;
        for (Node child : root.children) {
            PreorderTraverser(child);
        }
        return;
    }
}