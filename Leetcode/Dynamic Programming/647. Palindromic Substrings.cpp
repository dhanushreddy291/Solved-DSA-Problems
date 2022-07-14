class Solution {
public:
    int countSubstrings(string s) {
        int N = s.size(), palindromes = 0;
        int isPalindrome[N][N];
        memset(isPalindrome, 0, sizeof(isPalindrome));
        for (int length = 1; length <= N; length++) {
            int i = 0, j = i + length - 1;
            for (int i = 0, j = i + length - 1; j < N; i++, j++) {
                if (length == 1) isPalindrome[i][j] = 1;
                else if (length == 2) isPalindrome[i][j] = s[i] == s[j];
                else isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
                palindromes += isPalindrome[i][j];
            }
        }
        return palindromes;
    }
};