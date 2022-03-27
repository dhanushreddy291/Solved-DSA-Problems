class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector <vector <int>> Soldier(mat[0].size() + 1);
        for (int i = 0; i < mat.size(); i++) {
            int numberOfSoldiers = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                numberOfSoldiers += mat[i][j];
            }
            Soldier[numberOfSoldiers].push_back(i);
        }
        vector <int> Answer;
        for (int i = 0; i < Soldier.size() && Answer.size() < k; i++) {
            for (int j = 0; j < Soldier[i].size() && Answer.size() < k ; j++) {
                Answer.push_back(Soldier[i][j]);
            }
        }
        return Answer;
    }
};