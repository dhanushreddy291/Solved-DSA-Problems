class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int N = nums.size(), subsequences = 0;
        vector <unordered_map <int, int>> Map(N);
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                long d = (long)nums[i] - (long)nums[j];
                if (d < INT_MAX && d > INT_MIN) {
                    int apsEndingAtj = Map[j][d];
                    Map[i][d] += apsEndingAtj + 1;
                    subsequences += apsEndingAtj;
                }
            }
        }
        return subsequences;
    }
};