class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size(), dist = N - 1;
        for (int i = N - 2 ; i >= 0; i--) {
            if (nums[i] >= dist - i) dist = i;
        }
        return dist == 0;
    }
};