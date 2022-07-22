class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int N = s.size();
        vector <int> Ans(N, N);
        int pos = -1;
        for (int i = 0; i < N; i++) {
            if (s[i] == c) pos = i;
            if (pos != -1) Ans[i] = i - pos;
        }
        pos = -1;
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] == c) pos = i;
            if (pos != -1) Ans[i] = min(pos - i, Ans[i]);
        }
        return Ans;
    }
};