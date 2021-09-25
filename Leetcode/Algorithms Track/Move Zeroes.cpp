class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        for (j = 0; j < nums.size(); j++)
            if (nums[j]) nums[i++] = nums[j];
        for (int k = i; k < nums.size(); k++)
            nums[k] = 0;
    }
};