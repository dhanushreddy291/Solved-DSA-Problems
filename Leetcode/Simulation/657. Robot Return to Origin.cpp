class Solution {
public:
    bool judgeCircle(string moves) {
        int length = moves.size();
        int X = 0, Y = 0;
        for (int i = 0; i < length; i++) {
            if (moves[i] == 'U') Y++;
            else if (moves[i] == 'D') Y--;
            else if (moves[i] == 'L') X--;
            else X++;
        }
        return X == Y && X == 0;
    }
};