class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> Map;
        for (int i = 0; i < nums.size(); i++) {
            if (Map.find (target - nums[i]) != Map.end()) return {Map[target - nums[i]], i};
            Map[nums[i]] = i;
        }
        return {};
    }
};