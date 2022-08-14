class Solution {
private:
    bool cmp(vector <int> &A, vector <int> &B) {
        if (A[0] == B[0]) return A[1] > B[1];
        return A[0] < B[0];
    }
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        int N = items.size();
        vector <vector <int>> Answer;
        sort(items.begin(), items.end(), cmp);
        int id = -1, i = 0;
        while (i < N) {
            if (id == -1) {
                int count = 0;
                id = items[i][0];
                while (i < N && count < 5) {
                    Sum += items[i++][1];
                    count++;
                }
                while (i < N && items[i][0] == id) i++;
                Answer.push_back({id, Sum / 5});
                id = -1;
            }
        }
        return Answer;
    }
};