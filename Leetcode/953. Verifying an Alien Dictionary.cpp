class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector <int> Map(26, 0);
        for (char &c: order) {
            Map[(c - 'a')]++;
        }
        for (string &word: words) {
            for (char &c: word) {
                c = (Map[(c - 'a')] + 'a');
            }
        }
        return is_sorted(words.begin(), words.end(), strcmp);
    }
};