class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if (k == 0) return unique(nums.begin(), nums.end()) - nums.begin();
        int partitions = 0, Min = nums[0], Max = nums[0];
        for (int &num : nums) {
            Min = min(Min, num);
            Max = max(Max, num);
            if (Max - Min > k) {
                partitions++;
                Min = Max = num;
            }
        }
        return ++partitions;
    }
};