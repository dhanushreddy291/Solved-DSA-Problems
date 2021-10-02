class Solution {
public:
    int hammingWeight(uint32_t n) {
        int HammingWeight = 0;
        while (n) {
            n &= (n - 1);
            ++HammingWeight;
        }
        return HammingWeight;
    }
};