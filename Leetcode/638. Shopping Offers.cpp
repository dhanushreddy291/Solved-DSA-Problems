class Solution {
private:
    void DiscardUnnecessaryOffers(vector<vector<int>>& special, vector<int> &price, vector<vector<int>>& CorrectOffers, vector<int>& needs) {
        int N = special.size(), M = special[0].size() - 1;
        for (int i = 0; i < N; i++) {
            int Sum = 0;
            bool isValid = true;
            for (int j = 0; j < M; j++) {
                Sum += special[i][j] * price[j];
                if (special[i][j] > needs[j]) {
                    isValid = false;
                    break;
                }
            }
            if (!isValid) continue;
            if (Sum >= special[i][M]) 
            CorrectOffers.push_back(special[i]);
        }
        return;
    }
    int FindMinCost(vector<int>& price, vector <vector <int>> &CorrectOffers, vector<int>& needs) {
        bool containsAllZeroes = true;
        for (int i = 0; i < needs.size(); i++) {
            if (needs[i] != 0) {
                containsAllZeroes = false;
                break;
            }
        }
        if (containsAllZeroes) return 0;
        int MinCost = INT_MAX;
        for (int i = 0; i < CorrectOffers.size(); i++) {
            bool isValid = true;
            for (int j = 0; j < needs.size(); j++) {
                if (needs[j] < CorrectOffers[i][j]) {
                    isValid = false;
                    break;
                };
            }
            if (isValid) {
                for (int j = 0; j < needs.size(); j++) needs[j] -= CorrectOffers[i][j];
                MinCost = min(MinCost, CorrectOffers[i].back() + FindMinCost(price, CorrectOffers, needs)); 
                for (int j = 0; j < needs.size(); j++) needs[j] += CorrectOffers[i][j];
            } else {
                int Cost = 0;
                for (int i = 0; i < needs.size(); i++) 
                    Cost += needs[i] * price[i]; 
                MinCost = min(MinCost, Cost);
            }
        }
        return MinCost;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        vector <vector <int>> CorrectOffers;
        DiscardUnnecessaryOffers(special, price, CorrectOffers, needs);
        if (CorrectOffers.size() == 0) {
            int Cost = 0;
            for (int i = 0; i < needs.size(); i++) 
                Cost += needs[i] * price[i]; 
            return Cost;
        }
        return FindMinCost(price, CorrectOffers, needs);
    }
};