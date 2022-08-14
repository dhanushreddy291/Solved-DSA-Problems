class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> indexes;
        int N = s.size(), M = p.size(), i = 0;
        if (M > N) return {};
        vector <int> Map1(26, 0), Map2(26, 0);
        for (char &ch: p) {
            Map1[ch - 'a']++;
        }
        while (i < M) {
            Map2[s[i++] - 'a']++;
        }
        while (i < N) {
            if (Map1 == Map2) {
                indexes.push_back(i - M);
            }
            Map2[s[i - M] - 'a']--;
            Map2[s[i++] - 'a']++;
        }
        return indexes;
    }
};