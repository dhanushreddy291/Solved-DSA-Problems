class Solution {
private:
    bool helper(vector<vector<int>>& matrix, int R, int C, int N, int target) {
        if (R >= N || C < 0) return false;
        int idx = lower_bound(matrix[R].begin(), matrix[R].begin() + C, target) - matrix[R].begin();
        if (matrix[R][idx] == target) return true;
        if (idx > C) return helper(matrix, R + 1, C, N, target);
        return helper(matrix, R + 1, idx, N, target);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size(), M = matrix[0].size();
        if (matrix[N - 1][M - 1] < target || matrix[0][0] > target) return false;
        return helper(matrix, 0, M - 1, N, target);
    }
};