class Solution {
private:
    vector <int> freqMap;
    int helper(vector <string> &words, vector <int> &score, int index) {
        if (index == words.size()) return 0;
        int leaveIt = helper(words, score, index + 1);
        int pickIt = 0;
        bool canIPickIt = true;
        for (char &ch: words[index]) {
            pickIt += score[ch - 'a'];
            if (freqMap[ch - 'a'] == 0) {
                canIPickIt = false;
            }
            freqMap[ch - 'a']--;
        }
        if (canIPickIt) {
            pickIt += helper(words, score, index + 1);
        }
        for (char &ch: words[index]) {
            freqMap[ch - 'a']++;
        }
        return max(pickIt, leaveIt);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        maxScore = 0;
        freqMap = vector <int> (26, 0);
        for (char &ch: letters) {
            freqMap[ch - 'a']++;
        }
        return helper(words, score, i);
    }
};