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
    public List<Integer> postorder(Node root) {
        PostOrderTraverser(root);
        Collections.reverse(Answer);
        return Answer;
    }
    private void PostOrderTraverser(Node root) {
        if (root == null) return;
        Answer.add(root.val);
        if (root.children == null) return;
        int Size = root.children.size();
        for (int i = Size - 1; i >= 0; i--) {
            PostOrderTraverser(root.children.get(i));
        }
        return;
    }
}