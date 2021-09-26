class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector <int> Alphabets (26, 0);
        for (char &c : magazine)
            Alphabets[(c - 'a')]++;
        for (char &c : ransomNote)
            if (--Alphabets[(c - 'a')] < 0) return false;
        return true;
    }
};