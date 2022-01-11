class Solution {
private:
    string stringmaker(int N) {
        string Temp = "", whiteSpaces = " ";
        if (N < 1) return Temp;
        else while (N--) Temp += whiteSpaces;
        return Temp;
    }    
public:
    vector<string> printVertically(string s) {
        vector<string> Answer;
        int N = s.size(), i = 0, index = 0;
        while (i < N) {
            if (s[i] == ' ') index = 0;
            else if (index < Answer.size()) Answer[index] += s[i]; 
            else {
                Answer.push_back(Answer.size() ? stringmaker(Answer.back().size() - 1) : "");
                Answer[index] += s[i];
            }
            i++;
            index++;
        }
        return Answer;
    }
};