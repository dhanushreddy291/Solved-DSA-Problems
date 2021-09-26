class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int MaxSum = INT_MIN, i = 0, Sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            Sum += nums[i];
            MaxSum = max (MaxSum, Sum);
            Sum = max (Sum, 0);
        }
        return MaxSum;
    }
};