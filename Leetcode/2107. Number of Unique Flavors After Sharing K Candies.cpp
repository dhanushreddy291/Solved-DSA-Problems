class Solution {
private:
    unordered_map <int, int> Map;
public:
    int shareCandies(vector<int>& candies, int k) {
        for (int& candy: candies) {
            Map[candy]++;
        }
        int N = candies.size(), maxFlavors = 0;
        if (k == 0) return Map.size();
        for (int i = 0; i < N; i++) {
            Map[candies[i]]--;
            if (Map[candies[i]] == 0) Map.erase(candies[i]);
            if (i >= k - 1) {
                if (Map.size() > maxFlavors) maxFlavors = Map.size();
                Map[candies[i - k + 1]]++;
            }
        }
        return maxFlavors;
    }
};