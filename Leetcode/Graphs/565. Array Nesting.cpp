class Solution {
private:
    int DFS(vector<int>& nums, vector <bool> &Visited, int i) {
        if (Visited[i]) return 0;
        Visited[i] = true;
        return 1 + DFS(nums, Visited, nums[i]);
    }
public:
    int arrayNesting(vector<int>& nums) {
        int N = nums.size(), maxLength = 0;
        vector <bool> Visited(N, false);
        for (int i = 0; i < N; i++) {
            maxLength = max(maxLength, DFS(nums, Visited, i));
        }
        return maxLength;
    }
};