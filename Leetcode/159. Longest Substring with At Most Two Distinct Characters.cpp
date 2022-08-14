class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start = 0, end = 0, N = s.size(), length = 0;
        unordered_map <int, int> Map;
        for (int i = 0; i < N; i++) {
            if (Map.find(s[i]) != Map.end()) {
                Map[s[i]]++;
            } else {
                while (Map.size() == 2) {
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