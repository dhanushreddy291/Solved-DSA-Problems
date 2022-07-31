class Solution {
private:
    bool cmp(vector<int> &A, vector<int> &B) {
        return A[0] > B[0];
    }
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end(), cmp);
        int N = intervals.size(), start = intervals[0], end = start + 1;
        for (int i = 1; i < N; i++) {
            start = min(start, intervals[i][1] - 1);
            end = max(end, intervals[i][0] + 1);
        }
        return end - start + 1;
    }
};