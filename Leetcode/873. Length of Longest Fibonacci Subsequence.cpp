class Solution {
private:
    int helper(vector<int> &A, unordered_map <int, int> &DP, int i, int j, int N) {
        if (j >= N) return 0;
        int Val = A[i] + A[j];
        if (DP.find(Val) != DP.end()) return DP[Val];
        int idx = lower_bound(A.begin() + j, A.end(), Val) - A.begin();
        if (idx == N || A[idx] != Val) return DP[Val] = 2;
        return DP[Val] = 1 + helper(A, DP, j, idx, N);
    }
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int N = A.size(), Ans = 0;
        unordered_map <int, int> DP;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                Ans = max(Ans, helper(A, DP, i, j, N));
            }
        }
        return (Ans > 2) ? Ans : 0;
    }
};