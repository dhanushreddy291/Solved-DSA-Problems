class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set <string> stringSet;
        int N = s.size(), maxSize = 0, M = wordDict.size();
        vector <vector <string>> Map(N);
        for (int i = 0; i < M; i++) {
            if (wordDict[i].size() > maxSize) {
                maxSize = wordDict[i].size();
            }
            stringSet.insert(wordDict[i]);
        }
        for (int i = 0; i < N; i++) {
            for (int j = max(i - maxSize, 0); j <= i; j++) {
                if (stringSet.find(s.substr(j, i + 1 - j)) != stringSet.end()) {
                    if (j == 0) Map[i].push_back(s.substr(j, i + 1));
                    else {
                        for (int k = 0; k < Map[j - 1].size(); k++) {
                            Map[i].push_back(Map[j - 1][k] + " " + s.substr(j, i + 1 - j));
                        }
                    }
                }
            }
        }
        return Map[N - 1];
    }
};