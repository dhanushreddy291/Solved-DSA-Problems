class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (count(wordList.begin(), wordList.end(), endWord) == 0) return 0;
        unordered_set <string> Set;
        queue <pair <string, int>> Queue;
        unordered_map <string, vector <string>> Map;
        wordList.push_back(beginWord);
        int N = wordList.size(), M = beginWord.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                string x = wordList[i].substr(0, j) + '*' + wordList[i].substr(j + 1, M - j - 1);
                Map[x].push_back(wordList[i]);
            }
        }
        Queue.push({beginWord, 1});
        while (!Queue.empty()) {
            pair <string, int> P = Queue.front();
            Queue.pop();
            for (int j = 0; j < M; j++) {
                string x = P.first.substr(0, j) + '*' + P.first.substr(j + 1, M - j - 1);
                for (string &word: Map[x]) {
                    if (Set.find(word) != Set.end()) continue;
                    if (word == endWord) return P.second + 1;
                    Queue.push({word, P.second + 1});
                    Set.insert(word);
                }
            }
        }
        return 0;
    }
};