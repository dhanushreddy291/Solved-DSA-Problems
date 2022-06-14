class Solution {
public:
    string freqAlphabets(string s) {
        int N = s.size(), i = 0;
        string Ans = "";
        while (i++ < N) {
            if (i + 2 < N && s[i + 2] == '#') {
                Ans += ('j' + 10 * (s[i] - '0') + (s[i + 1] - '0') - 10);
                i += 2;
            }
            else Ans += ('a' + s[i] - '1');
        }
        return Ans;
    }
};