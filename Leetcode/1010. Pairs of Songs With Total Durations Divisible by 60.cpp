class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int N = time.size(), Count = 0;
        unordered_map <int, int> Map;
        for (int i = 0; i < N; i++) {
            int Time = time[i] % 60;
            if (Map.find(60 - Time) != Map.end()) Count += Map[60 - Time];
            Map[Time]++;
        }
        return Count + (Map[0] * (Map[0] - 1))/2;
    }
};