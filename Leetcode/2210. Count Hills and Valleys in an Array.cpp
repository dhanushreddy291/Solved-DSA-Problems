class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int N = nums.size(), i = 1, count = 0;
        while (i < N - 1) {
            int j = i;
            while (i < N - 1 && nums[i] == nums[i + 1]) i++;
            if (i < N - 1 && ((nums[j - 1] < nums[i] && nums[i] > nums[i + 1]) || (nums[j - 1] > nums[i] && nums[i] < nums[i + 1]))) count++;
            i++;
        }
        return count;
    }
};