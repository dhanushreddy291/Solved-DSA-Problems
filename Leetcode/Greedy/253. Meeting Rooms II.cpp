class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int maxSize = 0;
        priority_queue <int, vector <int>, greater <int>> minHeap;
        sort (intervals.begin(), intervals.end());
        for (vector <int> &interval: intervals) {
            if (minHeap.empty()) {
                minHeap.push(interval[1]);
            } else {
                while (!minHeap.empty() && minHeap.top() <= interval[0]) {
                    minHeap.pop();
                }
                minHeap.push(interval[1]);
            }
            if (minHeap.size() > maxSize) maxSize = minHeap.size();
        }
        return maxSize;
    }
};