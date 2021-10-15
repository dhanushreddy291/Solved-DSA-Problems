class Solution {
public:
    static bool Comparator (vector<int> &Interval1, vector <int> &Interval2) {
        return Interval1[0] < Interval2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector <vector <int>> Answer;
        sort (intervals.begin(), intervals.end(), Comparator);
        int L = intervals[0][0], R = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (R >= intervals[i][0]) {
                R = max (intervals[i][1], R);
            } else {
                Answer.push_back({L, R});
                L = intervals[i][0];
                R = intervals[i][1];
            }
        }
        Answer.push_back({L, R});
        return Answer;
    }
};