class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N = nums.size(), Sum = accumulate(nums.begin(), nums.end(), 0);
        if (Sum & 1) return false;
        vector <bool> DP(Sum/2 + 1, false);
        DP[0] = true;
        for (int i = 0; i < N; i++) {
            for (int sum = Sum/2; sum >= 1; sum--) {
                if (nums[i] <= sum && !DP[sum]) {
                    DP[sum] = DP[sum - nums[i]];
                }
            }
        }
        return DP[Sum/2];
    }
};