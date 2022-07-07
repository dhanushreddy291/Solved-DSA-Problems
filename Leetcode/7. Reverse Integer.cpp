class Solution {
public:
    int reverse(int x) {
        int newNum = 0;
        while (x) {
            if(newNum > INT_MAX / 10 || newNum < INT_MIN / 10) return 0;
            newNum = 10 * newNum + x % 10;
            x /= 10;
        }
        return newNum;
    }
};