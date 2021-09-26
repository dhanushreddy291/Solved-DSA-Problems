class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r * c != mat.size() * mat[0].size()) return mat;
        vector <vector <int>> NewMatrix (r, vector <int> (c, 0));
        int i = 0, j = 0, x = 0, y = 0;
        while (i < mat.size()) {
            NewMatrix[x][y++] = mat[i][j++];
            if (j >= mat[0].size()) {j = 0; i++;}
            if (y >= c) {y = 0; x++;}
        }
        return NewMatrix;
    }
};