class Solution {
private:
    int maxPalindrome(int i, int j, int N, string &s) {
        if (i < 0 || j >= N) return 0;
        else if (s[i] == s[j]) return 2 + maxPalindrome(i - 1, j + 1, N, s);
        else return 0;
    }
public:
    string longestPalindrome(string s) {
        int maxLength = 1, N = s.size(), index = 0;
        for (int i = 0; i < N - 1; i++) {
            int palindromeLength = 1 + maxPalindrome(i - 1, i + 1, N, s);
            if (s[i] == s[i + 1]) palindromeLength = max(palindromeLength, 2 + maxPalindrome(i - 1, i + 2, N, s));
            if (palindromeLength > maxLength) {
                maxLength = palindromeLength;
                index = i;
            }
        }
        return maxLength & 1 ? s.substr(index - maxLength/2, maxLength) : s.substr(index - maxLength/2 + 1, maxLength);
    }
};


// DP Solution

class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size(), start = 0, maxLength = 0;
        vector <vector <bool>> DP(N, vector <bool> (N));
        for (int length = 0; length < N; length++) {
            for (int i = 0, j = length; j < N; i++, j++) {
                if (i == j) DP[i][j] = true;
                else if (length == 1) DP[i][j] = (s[i] == s[j]);
                else DP[i][j] = (s[i] == s[j] && DP[i + 1][j - 1]);
                if (DP[i][j] and j - i + 1 > maxLength) {
                    maxLength = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLength);
    }
};