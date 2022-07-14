class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        if (N == 1) return nums[0];
        vector <int> Val;
        for (int i = 0; i < N; i++) {
            if (i > 0 && i < N) val = nums[i - 1] * nums[i + 1];
            else if (i > 0) val = nums[i - 1];
            else val = nums[i + 1];
            Val.push_back(val);
        }
        int Max = 0;
        for (int i = 1; i < N; i++) {
            if (Val[i] > Val[Max]) Max = i;
        }
        int j = 0, Sum = Val[Max] * num[Max];
        Val.pop_back();
        for (int i = 0; i < N; i++) {
            if (i != Max) Val[j++] = nums[i];
        }
        return Sum + maxCoins(Val);
    }
};