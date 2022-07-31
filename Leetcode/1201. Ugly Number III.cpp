class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        vector <int> nums = {a, b, c}, pointer = {1, 1, 1};
        unordered_set <int> Set = {a, b, c};
        sort(nums.begin(), nums.end());
        int Ans = nums[0];
        for (int i = 1; i <= n; i++) {
            int ans = INT_MAX;
            for (int j = 0; j < 3; j++) {
                ans = min(ans, nums[j] * pointer[j]);
            }
            for (int j = 0; j < 3; j++) {
                if (ans == nums[j] * pointer[j]) {
                    pointer[j]++;
                    if (Set.find(nums[j] * pointer[j]) == Set.end()) {
                        Set.erase(nums[j] * (pointer[j] - 1));
                        Set.insert(nums[j] * pointer[j]);
                    }
                };
            }
            Ans = ans;
        }
        return Ans;
    }
};