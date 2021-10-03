class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) return {};
        vector <vector <int>> Matrix (m, vector <int> (n));
        int i = 0, j = 0, k = 0;
        while (i < m) {
            Matrix[i][j++] = original[k++];
            if (j == n) {
                j = 0;
                i++;
            }
        }
        return Matrix;
    }
};