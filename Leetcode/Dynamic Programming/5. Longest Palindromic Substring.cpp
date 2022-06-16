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