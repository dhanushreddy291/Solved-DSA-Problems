#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int firstMissingPositive(vector <int> &nums);
}

// Approach is to use the array itself as an HashMap if element at an index is positive it 
// signifies there is no element present in the array.
int Solution::firstMissingPositive(vector <int> &nums) {
    for (auto &num : nums)
        if (num < 1)
            num = nums.size() + 2;
    for (auto &num : nums)
        if (abs(num) > 0 && abs(num) <= nums.size())
            if (nums[abs(num) - 1] > 0)
                nums[abs(num) - 1] *= -1;
    int i = 0;        
    for (i = 0; i < nums.size(); i++)
        if (nums[i] > 0)
            break;        
    return i + 1;
}

int main()
{

	return 0;
}