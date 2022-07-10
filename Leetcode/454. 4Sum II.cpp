class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int A = nums1.size(), B = nums2.size(), C = nums3.size(), D = nums4.size(), count = 0;
        unordered_map <int, int> freqMap;
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                freqMap[nums1[i] + nums2[j]]++;
            }
        }
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < D; j++) {
                int sum = - nums3[i] - nums4[j];
                if (freqMap.find(sum) != freqMap.end()) {
                    count += freqMap[sum];
                }
            }
        }
        return count;
    }
};