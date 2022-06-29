class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector <vector <int>> Answer;
        priority_queue <pair <int, vector <int>>> Heap;
        int N = nums1.size(), M = nums2.size();
        set <pair <int, int>> Set;
        Heap.push({-nums1[0] - nums2[0], {0, 0}});
        if (k > (long)N * M) k = N * M;
        while (k--) {
            pair <int, vector <int>> Min = Heap.top();
            Heap.pop();
            Answer.push_back({nums1[Min.second[0]], nums2[Min.second[1]]});
            if (Min.second[0] + 1 < N) {
                if (Set.find({Min.second[0] + 1, Min.second[1]}) == Set.end()) {
                    Set.insert({Min.second[0] + 1, Min.second[1]});
                    Heap.push({-nums1[Min.second[0] + 1] - nums2[Min.second[1]], {Min.second[0] + 1, Min.second[1]}});
                }
            }
            if (Min.second[1] + 1 < M) {
                if (Set.find({Min.second[0], Min.second[1] + 1}) == Set.end()) {
                    Set.insert({Min.second[0], Min.second[1] + 1});
                    Heap.push({-nums1[Min.second[0]] - nums2[Min.second[1] + 1], {Min.second[0], Min.second[1] + 1}});  
                }
            }
        }
        return Answer;
    }
};