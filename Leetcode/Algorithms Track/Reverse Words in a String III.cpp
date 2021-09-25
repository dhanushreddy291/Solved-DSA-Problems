class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while (i < s.size()) {
            int Start = i;
            while (i < s.size() && s[i] != ' ') i++;
            reverse (s.begin() + Start, s.begin() + i++);
        }
        return s;
    }
};