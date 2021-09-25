class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map <int, int> Nums;
        for (int i = 0; i < numbers.size(); i++) {
                if (Nums.find (target - numbers[i]) != Nums.end())
                    return {Nums[target - numbers[i]] + 1, i + 1};
            Nums[numbers[i]] = i;
        }
        return {};
    }
};