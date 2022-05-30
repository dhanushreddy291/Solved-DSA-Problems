class Solution {
private:
    long long helper(long long N, char C) {
        long long Answer = 0;
        vector <int> digits(10, 0);
        while (N) {
            digits[N%10]++;
            N /= 10;
        }
        if (C == '+') {
            if (digits[0]) {
                for (int i = 1; i < 10; i++) {
                    if (digits[i]) {
                        Answer = i;
                        digits[i]--;
                        break;
                    }
                }
            }
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < digits[i]; j++) {
                    Answer *= 10;
                    Answer += i;
                }
            }   
        } else {
            for (int i = 9; i >= 0; i--) {
                for (int j = 0; j < digits[i]; j++) {
                    Answer *= 10;
                    Answer += i;
                }
            }
        }
        return Answer;
    }
public:
    long long smallestNumber(long long num) {
        if (num < 0) {
            num *= -1;
            return -1 * helper(num, '-');
        } else return helper(num, '+');
    }
};