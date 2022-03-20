class Solution {
private:
    int score(vector <int> bobArrows, vector <int> aliceArrows) {
        int Score = 0;
        for (int i = 0; i < 12; i++) {
            if (aliceArrows[i] < bobArrows[i]) Score += i;
        }
        return Score;
    }
    void helper(int numArrows, vector <int> &aliceArrows, vector <int> &bobArrows, int position, int &maxScore, vector <int> &answerArrows) {
        if (numArrows == 0 || position == 0) {
            int currentScore = score(bobArrows, aliceArrows);
            if (currentScore > maxScore) {
                maxScore = currentScore;
                for (int i = 0; i < 12; i++) {
                    answerArrows[i] = bobArrows[i];
                }
                answerArrows[0] = numArrows;
            }
        } else if (position > 0 && numArrows > 0) {
            if (numArrows > aliceArrows[position]) {
                bobArrows[position] = aliceArrows[position] + 1;
                helper(numArrows - bobArrows[position], aliceArrows, bobArrows, position - 1, maxScore, answerArrows);
                bobArrows[position] = 0;
            }
            helper(numArrows, aliceArrows, bobArrows, position - 1, maxScore, answerArrows);
        }
        return;
    }
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector <int> bobArrows(12, 0), answerArrows(12, 0);
        int maxScore = 0;
        helper(numArrows, aliceArrows, bobArrows, 11, maxScore, answerArrows);
        return answerArrows;
    }
};