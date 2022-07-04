class Solution {
private:
    bool findPath(TreeNode* root, TreeNode* target, vector <pair <TreeNode*, char>> &Path) {
        if (root) {
            if (root == target) return true;
            if (root -> left) {
                Path.push_back({root, 'L'});
                bool foundLeftSide = findPath(root -> left, target, Path);
                if (foundLeftSide) return true;
                Path.pop_back();
            }
            if (root -> right) {
                Path.push_back({root, 'R'});
                bool foundRightSide = findPath(root -> right, target, Path);
                if (foundRightSide) return true;
                Path.pop_back();
            }
        }
        return false;
    }
    void findNeighbours(TreeNode* root, vector <int> &Neighbours, int dist, char direction = 'N') {
        if (root) {
            if (dist > 0) {
                if (direction == 'L') {
                    findNeighbours(root -> right, Neighbours, dist - 1, 'N');
                } else if (direction == 'R') {
                    findNeighbours(root -> left, Neighbours, dist - 1, 'N');
                } else {
                    findNeighbours(root -> left, Neighbours, dist - 1, 'N');
                    findNeighbours(root -> right, Neighbours, dist - 1, 'N');
                }
            } else if (dist == 0) Neighbours.push_back(root -> val);
        }
        return;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector <pair <TreeNode*, char>> Path;
        vector <int> Neighbours;
        findPath(root, target, Path);
        findNeighbours(target, Neighbours, k);
        int pathSize = Path.size();
        for (int i = pathSize - 1; i >= 0; i--) {
            pair <TreeNode*, char> pathNode = Path[i];
            int dist = k - (pathSize - i);
            if (dist >= 0) findNeighbours(pathNode.first, Neighbours, dist, pathNode.second);
        }
        return Neighbours;
    }
};