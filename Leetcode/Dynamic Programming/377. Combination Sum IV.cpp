class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector <int> ways(target + 1, 0);
        ways[0] = 1;
        for (int sum = 1; sum <= target; sum++) {
            for (int &num: nums) {
                if (sum >= num && long(ways[sum]) + ways[sum - num] < INT_MAX) {
                    ways[sum] += ways[sum - num];
                }
            }
        }
        return ways[target];
    }
};