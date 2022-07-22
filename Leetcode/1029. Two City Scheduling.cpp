class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int Ans = 0;
        priority_queue <pair <int, int>, vector <pair <int, int>>, greater<pair <int, int>>> HeapA, HeapB;
        for (vector <int> &cost: costs) {
            if (cost[0] < cost[1]) HeapA.push({cost[1] - cost[0], cost[0]});
            else HeapB.push({cost[0] - cost[1], cost[1]});
        }
        while (HeapA.size() < HeapB.size()) {
            pair <int, int> Top = HeapB.top();
            HeapA.push({0, Top.first + Top.second});
            HeapB.pop();
        }
        while (HeapA.size() > HeapB.size()) {
            pair <int, int> Top = HeapA.top();
            HeapB.push({0, Top.first + Top.second});
            HeapA.pop();
        }
        while (!HeapA.empty()) {
            Ans += HeapA.top().second + HeapB.top().second;;
            HeapA.pop();
            HeapB.pop();
        }
        return Ans;
    }
};