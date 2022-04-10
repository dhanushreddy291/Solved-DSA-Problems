class Solution {
private:
    int convertToInt(string &s) {
        int Num = 0, N = s.size(), i = 0;
        bool isNegative = false;
        if (s[0] == '-') {
            isNegative = true;
            i++;
        }
        for (; i < s.size(); i++) {
            Num = 10 * Num + (s[i] - '0');
        }
        if (isNegative) return -1 * Num;
        else return Num;
    }
public:
    int calPoints(vector<string>& ops) {
        vector <int> Operations;
        Operations.push_back(convertToInt(ops[0]));
        for (int i = 1; i < ops.size(); i++) {
            if (ops[i][0] == 'C') Operations.pop_back();
            else if (ops[i][0] == 'D') Operations.push_back(Operations.back() * 2);
            else if (ops[i][0] == '+') Operations.push_back(Operations.back() + Operations[Operations.size() - 2]);
            else Operations.push_back(convertToInt(ops[i]));
        }
        int points = 0;
        for (int num : Operations) {
            points += num;
        }
        return points;
    }
};