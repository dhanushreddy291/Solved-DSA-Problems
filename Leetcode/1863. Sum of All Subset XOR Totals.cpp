class Solution {
private:
    int helper(vector<int> &nums, int i, int N, int XOR) {
        return i == N ? XOR : helper(nums, i + 1, N, XOR) + helper(nums, i + 1, N, XOR ^ nums[i]);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        // either pick it or leave it and add to sum
        return helper(nums, i, nums.size(), 0);
    }
};