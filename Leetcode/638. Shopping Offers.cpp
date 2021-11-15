class Solution {
private:
    int FindMinCost(vector<int>& price, vector <vector <int>> &special, vector<int>& needs) {
        int MinCost = INT_MAX, N = special.size(), M = needs.size();
        for (int i = 0; i < N; i++) {
            bool isValid = true;
            for (int j = 0; j < M; j++) {
                if (needs[j] < special[i][j]) {
                    isValid = false;
                    break;
                };
            }
            if (isValid) {
                for (int j = 0; j < M; j++) {
                    needs[j] -= special[i][j];
                }
                MinCost = min(MinCost, special[i].back() + FindMinCost(price, special, needs)); 
                for (int j = 0; j < M; j++) {
                    needs[j] += special[i][j];
                }
            }
        }
        return min(MinCost, MinCostWhenEmpty(needs, price, M));
    }
    int MinCostWhenEmpty(vector <int> &needs, vector <int> &price, int M) {
        int Cost = 0;
        for (int i = 0; i < M; i++) 
            Cost += needs[i] * price[i]; 
        return Cost;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return FindMinCost(price, special, needs);
    }
};