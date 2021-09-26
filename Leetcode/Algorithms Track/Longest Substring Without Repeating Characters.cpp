class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int MaxLength = 0, i = 0, j = 0;
        unordered_map <char, int> Freq;
        while (i < s.size()) {
            if (Freq[s[i]] == 0) Freq[s[i]]++;
            else {
                while (Freq[s[i]] != 0)
                    Freq[s[j++]]--;
                Freq[s[i]]++;
            }
            MaxLength = max (MaxLength, i++ - j + 1);
        }
        return MaxLength;
    }
};