class Solution {
private:
    int N;
    vector <vector <int>> DP;
    int helper(int L, int R, vector <int> &nums) {
        if (L > R) return 0;
        if (DP[L][R] != -1) return DP[L][R];
        for (int i = L; i <= R; i++) {
            DP[L][R] = max(DP[L][R], helper(L, i - 1, nums) + helper(i + 1, R, nums) + nums[i] * ((L > 0) ? nums[L - 1] : 1) * ((R + 1 < N) ? nums[R + 1] : 1));
        }
        return DP[L][R];
    }
public:
    int maxCoins(vector<int>& nums) {
        N = nums.size();
        DP = vector <vector <int>> (N, vector <int> (N, -1));
        return helper(0, nums.size() - 1, nums);
    }
};