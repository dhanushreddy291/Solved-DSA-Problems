class Solution {
public:
    int minCut(string s) {
        int N = s.size(), palindromes = 0;
        int isPalindrome[N][N];
        memset(isPalindrome, 0, sizeof(isPalindrome));
        for (int length = 1; length <= N; length++) {
            int i = 0, j = i + length - 1;
            for (int i = 0, j = i + length - 1; j < N; i++, j++) {
                if (length < 3) isPalindrome[i][j] = (s[i] == s[j]);
                else isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
            }
        }
        // A DP array which stores the minimum number of cuts required to partition the string
        // eg, palindromeCuts[i] gives the minimum cuts required to partition the string from s[0] to s[i] such that each partition is a Palindrome
        int palindromeCuts[N];
        palindromeCuts[0] = 0;
        for (int j = 1; j < N; j++) {
            if (isPalindrome[0][j]) palindromeCuts[j] = 0;
            else {
                palindromeCuts[j] = INT_MAX;
                for (int i = j; i > 0; i--) {
                    if (isPalindrome[i][j]) {
                        palindromeCuts[j] = min(1 + palindromeCuts[i - 1], palindromeCuts[j]);
                    }
                }
            }
        }
        // From the DP Array, we need minimum cuts required for the total string, i.e, from s[0] to s[N - 1]
        return palindromeCuts[N - 1];
    }
};