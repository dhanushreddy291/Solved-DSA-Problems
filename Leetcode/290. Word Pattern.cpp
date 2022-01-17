class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream Stream(s);
        unordered_map <char, string> Map;
        unordered_set <string> Set;
        string Str;
        int i = 0;
        while (Stream >> Str) {
            if (Map.find(pattern[i]) != Map.end()) {
                if (Map[pattern[i]] != Str) return false;
            } 
            else if (Set.find(Str) == Set.end()) {
                Map[pattern[i]] = Str;
                Set.insert(Str);   
            }
            else return false;
            i++;
        }
        if (i >= pattern.size() && !(Stream >> Str)) return true;
        else return false;
    }
};