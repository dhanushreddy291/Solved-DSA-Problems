class Solution {
private:
    map <int, int> PowerValues;
    int calculatePowerValue(int N) {
        if (PowerValues.find(N) != PowerValues.end()) return PowerValues[N];
        else if (N == 1) return 0;
        else if (N % 2 == 0) return PowerValues[N] = 1 + calculatePowerValue(N/2);
        else return PowerValues[N] = 1 + calculatePowerValue(3 * N + 1);
    }
public:
    int getKth(int lo, int hi, int k) {
        PowerValues[0] = 0;
        for (int i = 1; i <= hi; i++) {
            calculatePowerValue(i);
        }
        vector <pair <int, int>> Answer;
        for (int i = lo; i <= hi; i++) {
            Answer.push_back({PowerValues[i], i});
        }
        sort(Answer.begin(), Answer.end());
        return Answer[k - 1].second;
    }
};