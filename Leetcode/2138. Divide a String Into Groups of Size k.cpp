class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector <string> Answer;
        int N = s.size();
        for (int i = 0; i < N; i += k) {
            if (i + k - 1 < N) Answer.push_back(s.substr(i, k));
            else {
                string temp = s.substr(i);
                while(temp.size() != k) temp += fill;
                Answer.push_back(temp);
            }
        }
        return Answer;
    }
};