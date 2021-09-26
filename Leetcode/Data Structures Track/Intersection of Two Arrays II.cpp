class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int> Freq1 (1001, 0), Freq2 (1001, 0), Answer;
        for (int &num : nums1) Freq1[num]++;
        for (int &num : nums2) Freq2[num]++;
        for (int i = 0; i <= 1000; i++) {
            int RepeatTimes = min (Freq1[i], Freq2[i]);
            while (RepeatTimes--) Answer.push_back (i);
        }
        return Answer;
    }
};