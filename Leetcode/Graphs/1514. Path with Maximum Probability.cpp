class Solution {
public:
    double P = 0;
    void FindMaxProbabilty (vector <vector <pair <int, double>> &Graph, vector <double> &Probability, int Source, int Destination) {
        if (Source == Destination) {
            Probability[Destination] = max (Probability[Destination], P);
        } else {
            for (int i = 0; i < Graph[Source].size(); i++) {
                Probability[Graph[Source][i]] = (Probability[Graph[Source][i].first] != 0) ? max (Probability[Graph[Source][i].first], Probability[Source] * Graph[Source][i].second) : Probability[Source] * Graph[Source][i].second);
            }
        }
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector <double> Probability (n, 0);
        vector <vector <pair <int, double>> Graph(n);
        for (int i = 0; i < Graph.size(); i++) {
            Graph[edges[i][0]].push_back (edges[i][1], succProb[i]);
        }
        Visited[start] = true;
        FindMaxProbabilty(Graph, Probability, start, end);
        return MaxProbability;
    }
};