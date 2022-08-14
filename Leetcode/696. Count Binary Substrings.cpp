class Solution {
public:
    int countBinarySubstrings(string s) {
        int zeroesOnLeft = 0, onesOnLeft = 0, N = s.size(), i = 0, count = 0;
        while (i < N) {
            if (s[i] == '0') {
                while (i < N && s[i] == '0') {
                    zeroesOnLeft++;
                    i++;
                }
                count += min(zeroesOnLeft, onesOnLeft);
                onesOnLeft = 0;
            } else {
                while (i < N && s[i] == '1') {
                    onesOnLeft++;
                    i++;
                }
                count += min(zeroesOnLeft, onesOnLeft);
                zeroesOnLeft = 0;
            }
        }
        return count;
    }
};