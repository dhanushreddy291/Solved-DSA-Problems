class Solution {
private:
    bool isPalindrome(string& s, int i, int j) {
        if (i >= j) return true;
        else return (s[i] == s[j] && isPalindrome(s, i + 1, j - 1));
    }
    void Helper(string& s, vector<vector<string>>& Answer, int i, vector<string>& Temp, string& StartingPart) {
        if (i >= s.size()) Answer.push_back(Temp);
        else if (StartingPart.size() == 0) {
            StartingPart += s[i];
            Temp.push_back(StartingPart);
            Helper(s, Answer, i + 1, Temp, StartingPart);
        } else {
            string k = Temp.back();
            if (k[0] == s[i] && isPalindrome(k, 1, k.size() - 1)) {
                Temp.back() += s[i];
                StartingPart += s[i];
                Helper(s, Answer, i + 1, Temp, StartingPart);
                Temp.back().pop_back();
                StartingPart.pop_back();
            }
            if (Temp.back() != StartingPart && StartingPart[0] == s[i] && isPalindrome(StartingPart, 1, StartingPart.size() - 1)) {
                StartingPart += s[i];
                vector<string> NewTemp;
                NewTemp.push_back(StartingPart);
                Helper(s, Answer, i + 1, NewTemp, StartingPart);
            } else StartingPart += s[i];
            k = "";
            k += s[i];
            Temp.push_back(k);
            Helper(s, Answer, i + 1, Temp, StartingPart);
            Temp.pop_back();
            StartingPart.pop_back();
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> Temp;
        string StartingPart = "";
        vector<vector<string>> Answer;
        Helper(s, Answer, 0, Temp, StartingPart);
        set<vector<string>> S;
        for (int i = 0; i < Answer.size(); i++) Set.insert(Answer[i]);
        vector<vector<string>> FinalAnswer;
        for (auto elem : setOfStr) FinalAnswer.push_back(elem);
        return FinalAnswer;
    }
};