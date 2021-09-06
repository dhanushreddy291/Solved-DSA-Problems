#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int majorityElement(vector<int>& nums);
}

int Solution::majorityElement(vector <int> &nums) {
    int Frequency = 0, MajorityElement;
    for (auto num : nums) {
        if (Frequency == 0) {
            Frequency++;
            MajorityElement = num;
        }
        else if (num == MajorityElement) 
            Frequency++
        else
        Frequency--;   
    }
    return MajorityElement;
}

int main()
{

	return 0;
}