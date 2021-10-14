class Solution {
public:
    int numSquares(int n) {
        vector <int> Squares(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++)
                Squares[i] = (Squares[i] == 0) ? 1 + Squares[i - j * j] : min (Squares[i], 1 + Squares[i - j * j]);
        }
        return Squares[n];
    }
};