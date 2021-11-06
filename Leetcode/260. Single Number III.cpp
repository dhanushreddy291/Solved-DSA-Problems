class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long Xor = 0;
        int N = nums.size(), XorSave, A = 0;
        for (int i = 0; i < N; i++) {
            Xor ^= nums[i];
        }
        XorSave = Xor;
        Xor &= -Xor;
        for (int i = 0; i < N; i++) {
            if (Xor & nums[i]) A ^= nums[i];
        }
        return {A, XorSave ^ A};
    }
};