class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> Answer = {-1, -1};
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == target) {
                if (Answer[0] == -1) Answer[0] = i;
                if (Answer[0] != -1) Answer[1] = i;
            }
            i++;
        }
        return Answer;
    }
};