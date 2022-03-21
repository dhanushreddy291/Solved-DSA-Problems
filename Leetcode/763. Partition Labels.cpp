class Solution {
private:
    void helper(string &s, unordered_map <char, int> &Map, int N) {
        for (int i = 0; i < N; i++) {
            Map[s[i]] = i;
        }
    }
public:
    vector<int> partitionLabels(string s) {
        int N = s.size(), i = 0;
        unordered_map <char, int> Map;
        helper(s, Map, N);
        vector <int> Answer;
        while (i < N) {
            int MaxIndex = Map[s[i]];
            if (MaxIndex > i) {
                int j = i + 1, MaxIndex2 = j;
                while (true) {
                    while (j < MaxIndex) MaxIndex2 = max (MaxIndex2, Map[s[j++]]);
                    if (MaxIndex2 > MaxIndex) {
                        j = MaxIndex + 1;
                        MaxIndex = MaxIndex2;
                    }
                    else break;
                }
                Answer.push_back(MaxIndex - i + 1);
                i = max(MaxIndex, MaxIndex2) + 1;
            } else {
                Answer.push_back(1);
                i++;
            }
        }
        return Answer;
    }
};