class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        int start = 0, end = 0, N = s.size(), length = 0;
        unordered_map <int, int> Map;
        for (int i = 0; i < N; i++) {
            if (Map.find(s[i]) != Map.end()) {
                Map[s[i]]++;
            } else {
                while (Map.size() == k) {
                    Map[s[start]]--;
                    if (Map[s[start]] == 0) Map.erase(s[start]);
                    length = max(length, i - start);
                    start++;
                }
                Map[s[i]]++;       
            }
        }
        return max(length, N - start);
    }
};