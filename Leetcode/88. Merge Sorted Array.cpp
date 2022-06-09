class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = N - 1, j = M - 1, k = N + M - 1;
        while (i >= 0 && j >= 0) {
            A[k--] = (A[i] > B[j]) ? A[i--] : B[j--];
        }
        while (j >= 0) A[k--] = B[j--];
        return;
    }
};