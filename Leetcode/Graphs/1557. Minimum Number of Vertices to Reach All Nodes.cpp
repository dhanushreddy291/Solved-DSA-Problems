class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector <int> Answer;
        vector <int> Indegree (n, 0);
        for (int i = 0; i < edges.size(); i++) Indegree[edges[i][1]]++;
        for (int i = 0; i < n; i++) {
            if (Indegree[i] == 0) Answer.push_back(i);
        }
        return Answer;
    }
};