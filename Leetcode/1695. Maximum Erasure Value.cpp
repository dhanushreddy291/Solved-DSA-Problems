class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0, j = 0, sum = 0, maxSum = 0, N = nums.size();
        set <int> Set;
        while (j < N && i <= j) {
            if (Set.find(nums[j]) == Set.end()) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
                Set.insert(nums[j++]);
            } else {
                while (nums[i] != nums[j]) {
                    sum -= nums[i];
                    Set.erase(Set.find(nums[i++]));
                }
                i++;
                j++;
            }
        }
        return maxSum;
    }
};