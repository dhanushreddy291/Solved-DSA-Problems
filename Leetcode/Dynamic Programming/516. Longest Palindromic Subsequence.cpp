class Solution {
private:
    int n;
    vector <vector <int>> DP;
    int helper(int i, int j, string &s, string &t) {
        if (i == n || j == n) return 0;
        if (DP[i][j] != -1) return DP[i][j];
        if (s[i] == t[j]) return DP[i][j] = 1 + helper(i + 1, j + 1, s, t);
        return DP[i][j] = max(helper(i + 1, j, s, t), helper(i, j + 1, s, t));
    }
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        n = s.size();
        DP = vector <vector <int>> (n, vector <int> (n, -1));
        return helper(0, 0, s, t);
    }
};