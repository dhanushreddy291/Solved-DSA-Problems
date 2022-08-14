class Solution {
private:
    unordered_set <int> Set;
    vector <int> Values;
    vector <vector <int>> Graph;
    void DFS(int idx, vector <int> &nums) {
        for (int &children: Graph[idx]) {
            if (Set.find(nums[children]) != Set.end()) continue;
            Set.insert(nums[children]);
            DFS(children, nums);
        }
    }
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size(), val = 2;
        Values = vector <int>(n, 1);
        Graph = vector <vector <int>>(n);
        for (int i = 1; i < n; i++) {
            Graph[parents[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                int idx = i;
                while (idx != -1) {
                    Set.insert(nums[idx]);
                    DFS(idx, nums);
                    while (Set.find(val) != Set.end()) val++;
                    Values[idx] = val;
                    idx = parents[idx];
                }
                break;
            }
        }
        return Values;
    }
};