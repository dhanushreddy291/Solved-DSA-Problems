class Solution {
private:
    void Permute(string &s, vector <string> &Permutations, int i, int N) {
        if (i == N) Permutations.push_back(s);
        else if (isalpha(s[i])) {
            Permute(s, Permutations, i + 1, N);
            if (islower(s[i])) {
                s[i] = toupper(s[i]);
                Permute(s, Permutations, i + 1, N);
            }
            else {
                s[i] = tolower(s[i]);
                Permute(s, Permutations, i + 1, N);
            }
        } else Permute(s, Permutations, i + 1, N);
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector <string> Permutations;
        Permute(s, Permutations, 0, s.size());
        return Permutations;
    }
};