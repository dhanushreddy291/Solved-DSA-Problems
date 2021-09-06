#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
} TreeNode;


class Solution {
    public:
    int solve(TreeNode* A)
} 

pair <int, int> Diameter (TreeNode* Root)
{
    if (Root == NULL) return {0, 0};
    pair <int, int> L = Diameter (Root -> left);
    pair <int, int> R = Diameter (Root -> right);
    return {max (L.first, R.first) + 1, max (max (L.second, R.second), L.first + R.first + 1)};
}

int Solution::solve(TreeNode* A) {
    return Diameter(A).second;
}

int main()
{

	return 0;
}