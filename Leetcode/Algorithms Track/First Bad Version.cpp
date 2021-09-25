// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0, end = n - 1, mid = (n - 1) / 2;
        while (start <= end) {
            if (isBadVersion(mid)) end = mid - 1;
            else start = mid + 1;
            mid = start + (end - start) / 2;
        }
        return start;
    }
};