class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector <int> freq(26, 0);
        for (char &ch: sentence) {
            freq[ch - 'a']++;
        }
        return *min_element(freq.begin(), freq.end()) > 0;
    }
};