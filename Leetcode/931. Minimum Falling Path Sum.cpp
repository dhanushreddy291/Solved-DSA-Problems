class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        for (int i = N - 2; i >= 0; i--) {
            for (int j = 0; j < M; j++) {
                int a = matrix[i + 1][j];
                if (j > 0) a = min(a, matrix[i + 1][j - 1]);
                if (1 + j < M) a = min(a, matrix[i + 1][j + 1]);
                matrix[i][j] += a;
            }
        }
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};