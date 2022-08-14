class Solution {

private:
    int size1, size2, sum1, sum2, maxSizeofSubset, minDiff;
    void findMinDiff(int i, vector <int> &nums) {

        if (size1 > maxSizeofSubset || size2 > maxSizeofSubset) return;

        if (i == N) {
            minDiff = min(minDiff, abs(sum1 - sum2));
        } else {

            size1 += 1;
            sum1 += nums[i];
            findMinDiff(i + 1, nums);
            size1 -= 1;
            sum1 -= nums[i];

            size2 += 1;
            sum2 += nums[i];
            findMinDiff(i + 1, nums);
            size2 -= 1;
            sum2 -= nums[i];

        }

        return;

    }

public:
    int minimumDifference(vector<int>& nums) {
        minDiff = INT_MAX;
        ss1 = 0;
        ss2 = 0;
        size1 = 0;
        size2 = 0;
        maxSizeofSubset = nums.size() / 2;
        findMinDiff(0, nums);
        return minDiff;
    }
};