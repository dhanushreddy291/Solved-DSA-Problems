    class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid = (start + end)/2;
        for (; start <= end; mid = (start + end)/2) {
            if (nums[mid] > target) 
                end = mid - 1;
            else if (nums[mid] == target)
                return mid;
            else start = mid + 1;
        }
        return -1;
    }
};