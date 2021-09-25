class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int Minimum = INT_MAX, i = 0;
            while (i < nums.size() && abs(nums[i]) <= Minimum)
                Minimum = abs(nums[i++]);
            int LStart = i - 2, RStart = i - 1, t = 0;
            vector <int> Answer (nums.size());
            while (LStart >= 0 && RStart < nums.size()) {
                if (abs(nums[LStart]) > abs(nums[RStart]))
                    Answer[t++] = nums[RStart] * nums[RStart++];
                else Answer[t++] = nums[LStart] * nums[LStart--];
            }
            while (LStart >= 0)
                Answer[t++] = nums[LStart] * nums[LStart--];
            while (RStart < nums.size())
                Answer[t++] = nums[RStart] * nums[RStart++];
            return Answer;
    }
};