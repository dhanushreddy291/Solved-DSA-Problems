class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int N = nums.size();
        vector <int> window;
        priority_queue <pair <int, int>> maxHeap;
        for (int i = 0; i < k - 1; i++) {
            maxHeap.push({nums[i], i});
        }
        for (int i = k - 1; i < N; i++) {
            maxHeap.push({nums[i], i});
            while (i - maxHeap.top().second >= k) {
                maxHeap.pop();
            }
            window.push_back(maxHeap.top().first);
        }
        return window;
    }
};