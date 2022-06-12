class Solution {
private:
    void Generator(int L, int R, string parenthesis) {
        if (L == 0 && R == 0) Answer.push_back(parenthesis);
        else {
            if (L > 0) Generator(L - 1, R, parenthesis + '(');
            if (R - L > 0) Generator(L, R - 1, parenthesis + ')');
        }
    }
public:
    vector <string> Answer;
    vector<string> generateParenthesis(int n) {
        Answer.clear();
        Generator(n, n, "");
        return Answer;
    }
};