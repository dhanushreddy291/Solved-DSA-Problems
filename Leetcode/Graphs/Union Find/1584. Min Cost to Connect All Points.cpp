class Comparator {
public:
    bool operator() (const vector <int> &Edge1, const vector <int> &Edge2) {
        return Edge1[1] >= Edge2[1];
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int connectionCost = 0;
        priority_queue <vector <int>, vector <vector <int>>, Comparator> minHeap;
        minHeap.push({0, 0});
        unordered_set <int> Visited;
        while (Visited.size() < points.size()) {
            vector <int> Top = minHeap.top();
            minHeap.pop();
            if (Visited.find(Top[0]) != Visited.end()) continue;
            Visited.insert(Top[0]);
            for (int i = 1; i < points.size(); i++) {
                if (Visited.find(i) == Visited.end()) {
                    minHeap.push({i, abs(points[Top[0]][0] - points[i][0]) + abs(points[Top[0]][1] - points[i][1])});
                }
            }
            connectionCost += Top[1];
        }
        return connectionCost;
    }
};