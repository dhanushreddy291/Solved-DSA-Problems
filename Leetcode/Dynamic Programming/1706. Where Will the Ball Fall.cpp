class Solution {
private:
    void Compute(vector<int> &Pos, vector<int> &Answer, bool isFirstRow = false) {
        if(isFirstRow){
            int Columns = Pos.size();
            for (int i = 0; i < Columns; i++) {
                if (Pos[i] == -1) {
                    if (i == 0) Answer[i] = -1;
                    else if (Pos[i] * Pos[i - 1] < 0) Answer[i] = -1;
                    else Answer[i] = i - 1;
                } else {
                    if (i == Columns - 1) Answer[i] = -1;
                    else if (Pos[i] * Pos[i + 1] < 0) Answer[i] = -1;
                    else Answer[i] = i + 1;
                }
            }
        } else {
            int Columns = Pos.size();
            vector <bool> shouldIVisit(Columns, false);
            vector <int> Temp(Columns, -1);
            for (int i = 0; i < Columns; i++) {
                if (Answer[i] != -1) shouldIVisit[Answer[i]] = true;
            }
            for (int i = 0; i < Columns; i++) {
                if (shouldIVisit[i]) {
                    if (Pos[i] == -1) {
                        if (i == 0) Temp[i] = -1;
                        else if (Pos[i] * Pos[i - 1] < 0) Temp[i] = -1;
                        else Temp[i] = i - 1;
                    } else {
                        if (i == Columns - 1) Temp[i] = -1;
                        else if (Pos[i] * Pos[i + 1] < 0) Temp[i] = -1;
                        else Temp[i] = i + 1;
                    }
                }
            }
            for (int i = 0; i < Columns; i++) {
                if (Answer[i] >= 0) Answer[i] = Temp[Answer[i]];
            }
        }
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int Rows = grid.size(), Columns = grid[0].size();
        vector <int> Answer(Columns);
        Compute(grid[0], Answer, true);
        for (int i = 1; i < Rows; i++) {
            Compute(grid[i], Answer);
        }
        return Answer;
    }
};