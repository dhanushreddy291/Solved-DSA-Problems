class Solution {
private:
    bool doTheStringsMatch(string &a, string &b) {
        int N = a.size();
        unordered_map <char, char> Map1, Map2;
        for (int i = 0; i < N; i++) {
            if (Map1.find(a[i]) == Map1.end()) {
                Map1[a[i]] = b[i];
            } else if (Map1[a[i]] != b[i]) return false;
            if (Map2.find(b[i]) == Map2.end()) {
                Map2[b[i]] = a[i];
            } else if (Map2[b[i]] != a[i]) return false;
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector <string> matchedPatterns;
        for (string& word: words) {
            if (doTheStringsMatch(word, pattern)) {
                matchedPatterns.push_back(word);
            }
        }
        return matchedPatterns;
    }
};