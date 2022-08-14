class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map <int, int> Map;
        int MOD = int(1e9 + 7), count = 0;
        for (int &num: arr) {
            Map[num]++;
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] != 0) continue;
                int val = arr[i] / arr[j];
                if (Map.find(val) != Map.end()) {
                    Map[arr[i]] = int((long(Map[arr[i]]) + long(Map[arr[j]]) * Map[val]) % MOD);
                }
            }
        }
        for (int &num: arr) {
            count = (count + Map[num]) % MOD;
        }
        return count;
    }
};