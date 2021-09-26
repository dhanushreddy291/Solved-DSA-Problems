class Solution {
public:
    int firstUniqChar(string s) {
        vector <int> Pos (26, INT_MAX), Freq (26, 0);
        for (int i = 0; i < s.size(); i++) {
            int c = (s[i] - 'a');
            Pos[c] = min (i, Pos[c]);
            Freq[c]++;
        }
        for (char &c : s)
            if (Freq[(c - 'a')] == 1) return Pos[(c - 'a')];
        return -1;
    }
};