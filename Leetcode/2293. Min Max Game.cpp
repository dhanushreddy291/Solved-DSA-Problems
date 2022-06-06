class Solution {
private:
    int helper(vector <int> &nums, int N) {
        if (N == 1) return nums[0];
        else {
            for (int i = 0; i < N / 2; i++) {
                nums[i] = (i % 2) ? max(nums[2 * i], nums[2 * i + 1]) : min(nums[2 * i], nums[2 * i + 1]);
            }
            return helper(nums, N / 2);
        }
    }
public:
    int minMaxGame(vector<int>& nums) {
        return helper(nums, nums.size());
    }
};