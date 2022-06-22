class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector <int>, greater <int>> Heap;
        for (int &num : nums) {
            if (Heap.size() < k) Heap.push(num);
            else if (Heap.top() < num) {
                Heap.pop();
                Heap.push(num);
            }
        }
        return Heap.top();
    }
};