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
            else if (Sum >= special[i][M]) 
                CorrectOffers.push_back(special[i]);
        }
        return;
    }
    int FindMinCost(vector<int>& price, vector <vector <int>> &CorrectOffers, vector<int>& needs) {
        int MinCost = INT_MAX, N = CorrectOffers.size(), M = needs.size();
        for (int i = 0; i < N; i++) {
            bool isValid = true;
            for (int j = 0; j < M; j++) {
                if (needs[j] < CorrectOffers[i][j]) {
                    isValid = false;
                    break;
                };
            }
            if (isValid) {
                for (int j = 0; j < M; j++) {
                    needs[j] -= CorrectOffers[i][j];
                }
                MinCost = min(MinCost, CorrectOffers[i].back() + FindMinCost(price, CorrectOffers, needs)); 
                for (int j = 0; j < M; j++) {
                    needs[j] += CorrectOffers[i][j];
                }
            } else MinCost = min(MinCost, MinCostWhenEmpty(needs, price, M));
        }
        return MinCost;
    }
    int MinCostWhenEmpty(vector <int> &needs, vector <int> &price, int M) {
        int Cost = 0;
        for (int i = 0; i < M; i++) 
            Cost += needs[i] * price[i]; 
        return Cost;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        vector <vector <int>> CorrectOffers;
        DiscardUnnecessaryOffers(special, price, CorrectOffers, needs);
        return (CorrectOffers.size() == 0) ? MinCostWhenEmpty(needs, price, needs.size()) : FindMinCost(price, CorrectOffers, needs);
    }
};