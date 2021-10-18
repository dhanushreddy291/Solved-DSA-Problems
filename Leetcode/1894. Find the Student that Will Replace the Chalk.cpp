class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       int N = chalk.size();
        vector <long> PrefixSum = {chalk[0]};
        for (int i = 1; i < N; i++) {
            PrefixSum.push_back(PrefixSum[i - 1] + chalk[i]);
        }
        k %= PrefixSum[N - 1];
        return upper_bound(PrefixSum.begin(), PrefixSum.end(), k) - PrefixSum.begin();
    }
};