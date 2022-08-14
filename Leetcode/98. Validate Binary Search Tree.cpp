class Solution {
private:
    long prevVal;
    bool helper(TreeNode* root) {
        if (root == NULL) return true;
        if (helper(root -> left)) {
            if (root -> val <= prevVal) return false;
            prevVal = root -> val;
            return helper(root -> right);
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        prevVal = long(INT_MIN) - 1;
        return helper(root);
    }
};