class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int Start = 0, End = 0;
        vector <vector <int>> Answer;
        while (End < s.size()) {
            char A = s[Start];
            while (End < s.size() && s[End] == A) End++;
            if (End - Start >= 3) Answer.push_back({Start, End - 1});
            Start = End;
        }
        return Answer;
    }
};