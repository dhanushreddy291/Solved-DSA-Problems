class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> Map;
        priority_queue <pair <int, int>> Heap;
        vector <int> Frequent;
        for (int &num: nums) Map[num]++;
        for (auto it = Map.begin(); it != Map.end(); it++) {
            Heap.push({it -> second, it -> first});
        }
        while (k--) {
            pair <int, int> num = Heap.top();
            Heap.pop();
            Frequent.push_back(num.second); 
        }
        return Frequent;
    }
};