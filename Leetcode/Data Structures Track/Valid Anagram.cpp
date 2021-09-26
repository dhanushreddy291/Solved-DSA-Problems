class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> Map1 (26, 0), Map2 (26, 0);
        for (char &c : s) Map1[(c - 'a')]++;
        for (char &c : t) Map2[(c - 'a')]++;
        return Map1 == Map2;
    }
};