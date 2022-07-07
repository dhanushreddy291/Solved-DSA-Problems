class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map <int, int> Map;
        for (int &num: nums) Map[num] = 1;
        longSeq = 0;
        for (auto it = Map.begin(); it != Map.end(); it++) {
            seqLength = 1;
            int L = it -> first - 1, R = it -> first + 1;
            while (Map.find(L) != Map.end()) {
                Map.erase(L);
                L--;
                seqLength++;
            }
            while (Map.find(R) != Map.end()) {
                Map.erase(R);
                R++;
                seqLength++;
            }
            longSeq = max(longSeq, seqLength);
        }
        return longSeq;
    }
};