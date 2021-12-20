class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector <vector <int>> Answer;
        int N = arr.size(), MinDiff = INT_MAX;
        sort (arr.begin(), arr.end());
        for (int i = 0; i < N - 1; i++) {
            MinDiff = min(MinDiff, arr[i + 1] - arr[i]);
        }
        for (int i = 0; i < N - 1; i++) {
            if (arr[i + 1] - arr[i] == MinDiff) {
                Answer.push_back({arr[i], arr[i + 1]});
            }
        }
        return Answer;
    }
};