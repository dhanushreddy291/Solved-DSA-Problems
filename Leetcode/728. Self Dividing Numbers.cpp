class Solution {
private:
    bool SelfDividing(int N) {
        int M = N, temp;
        while(M) {
            temp = M % 10;
            if (temp == 0 || N % temp != 0) return false;
            M /= 10;
        }
        return true;  
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> List;
        for (int i = left; i <= right; i++) {
            if (SelfDividing(i)) List.push_back(i);
        }
        return List;
    }
};