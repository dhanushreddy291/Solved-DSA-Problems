class Solution {
public:
    string removeDuplicateLetters(string s) {
        string cleanedString = "";
        stack <char> Stack;
        vector <int> freqMap(26, 0);
        vector <bool> present(26, false);
        for (char &ch: s) {
            freqMap[ch - 'a']++;
        }
        "bbcaac"
        for (char &ch: s) {
            if (!present[ch - 'a']) {
                while (!Stack.empty() && freqMap[Stack.top() - 'a'] > 0 && Stack.top() > ch) {
                    present[Stack.top() - 'a'] = false;
                    Stack.pop();
                }
                Stack.push(ch);
                present[ch - 'a'] = true;
            }
            freqMap[ch - 'a']--;
        }
        while (!Stack.empty()) {
            cleanedString += Stack.top();
            Stack.pop();
        }
        reverse(cleanedString.begin(), cleanedString.end());
        return cleanedString;
    }
};