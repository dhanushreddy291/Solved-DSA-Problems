class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        deque <int> maxQueue, minQueue;
        int start = 0, end = 0, N = nums.size(), maxLength = 0;
        
        while (end < N) {
            
            while (!maxQueue.empty() && nums[maxQueue.back()] <= nums[end]) {
                maxQueue.pop_back();
            }
            while (!minQueue.empty() && nums[minQueue.back()] >= nums[end]) {
                minQueue.pop_back();
            }
        
            maxQueue.push_back(end);
            minQueue.push_back(end);

            if (nums[maxQueue.front()] - nums[minQueue.front()] > limit) {
                if (start == minQueue.front()) minQueue.pop_front();
                if (start == maxQueue.front()) maxQueue.pop_front();
                start++;
            } else {
                maxLength = max(maxLength, end - start + 1);
                end++;
            }

        }

        return maxLength;
        
    }
};