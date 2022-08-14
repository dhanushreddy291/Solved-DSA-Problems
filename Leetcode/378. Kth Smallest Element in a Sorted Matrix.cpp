class Solution {
private:
    int count(vector<vector<int>>& matrix, int mid, int n) {
        int Count = 0;
        for (int i = 0; i < n; i++) {
            Count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        return Count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), lo = matrix[0][0], hi = matrix[n - 1][n - 1];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (count(matrix, mid, n) < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};