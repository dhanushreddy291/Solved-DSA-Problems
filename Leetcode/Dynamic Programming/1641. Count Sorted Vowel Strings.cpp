class Solution {
public:
    int countVowelStrings(int n) {
        vector <int> DP(5, 1);
        for (int i = 1; i <= n; i++) {
            vector <int> temp(5, 0);
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < j; k++) {
                    temp[i] += DP[k];
                }
            }
            for (int x = 0; x < 5; x++) {
                DP[x] = temp[x];
            }
        }    
    }
};