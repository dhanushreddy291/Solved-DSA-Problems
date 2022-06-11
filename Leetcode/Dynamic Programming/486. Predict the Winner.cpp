class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int N = nums.size();
        vector <vector <int>> DP(N, vector <int> (N, 0));
        for (int diagSize = N; diagSize > 0; diagSize--) {
            int i = 0, j = N - diagSize;
            while (j < N) {
                if (i == j) DP[i][j] = nums[i];
                else DP[i][j] = max(DP[i][i] - DP[i + 1][j], DP[j][j] - DP[i][j - 1]);
                i += 1;
                j += 1;
            }
        }
        return DP[0][N-1] >= 0;
    }
};