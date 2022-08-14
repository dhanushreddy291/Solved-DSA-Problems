class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int N = shifts.size();
        for (int i = N - 2; i >= 0; i--) {
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        }
        for (int i = 0; i < N; i++) {
            s[i] = 'a' + (s[i] - 'a' + shifts[i]) % 26;
        }
        return s;
    }
};