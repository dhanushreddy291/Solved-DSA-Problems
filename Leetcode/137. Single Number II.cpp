class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int Number = 0;
        for (int i = 0; i < 31; i++) {
            int bitsCount = 0;
            for (int &num: nums) {
                if (num & 1) bitsCount++;
                num >>= 1;
            }
            if (bitsCount % 3) {
                Number |= (1 << i);
            }
        }
        return Number;
    }
};