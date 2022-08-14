class Solution {
private:
    Solution* Words[26] = {};
    bool wordEnd;
    void insert(string &word) {
        Solution* Root = this;
        for (char &ch: word) {
            if (Root -> Words[ch - 'a'] == nullptr) {
                Root -> Words[ch - 'a'] = new Solution();
            }
            Root = Root -> Words[ch - 'a'];
        }
        Root -> wordEnd = true;
        return;
    }
public:
    Solution() {
        this -> wordEnd = false;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string &word: dictionary) {
            insert(word);
        }
        string cleanedSentence = "";
        int N = sentence.size(), i = 0;
        while (i < N) {
            if (sentence[i] == ' ') {
                cleanedSentence += sentence[i++];
            } else {
                string str = "";
                if (this -> Words[sentence[i] - 'a'] == nullptr) {
                    while (i < N && sentence[i] != ' ') {
                        str += sentence[i++];
                    }
                    cleanedSentence += str;
                } else {
                    Solution* Root = this;
                    while (i < N && sentence[i] != ' ') {
                        if (Root -> wordEnd || Root -> Words[sentence[i] - 'a'] == nullptr) break;
                        str += sentence[i];
                        Root = Root -> Words[sentence[i++] - 'a'];
                    }
                    string temp = "";
                    while (i < N && sentence[i] != ' ') {
                        temp += sentence[i++];
                    }
                    if (Root -> wordEnd) cleanedSentence += str;
                    else cleanedSentence += str + temp;
                }
            }
        }
        return cleanedSentence;
    }
};