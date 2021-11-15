class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int MinCost = INT_MAX, N = special.size(), M = needs.size();
        for (int i = 0; i < N; i++) {
            if (ValidOffer(needs, special, M, i)) {
                ModifyTheNeeds(needs, special, '-', M, i);
                MinCost = min(MinCost, special[i].back() + shoppingOffers(price, special, needs)); 
                ModifyTheNeeds(needs, special, '+', M, i);
            }
        }
        return min(MinCost, MinCostWhenEmpty(needs, price, M));
    }
private:
    int MinCostWhenEmpty(vector<int>& needs, vector<int>& price, int M) {
        int Cost = 0;
        for (int i = 0; i < M; i++) 
            Cost += needs[i] * price[i]; 
        return Cost;
    }
    void ModifyTheNeeds(vector<int>& needs, vector<vector<int>>& special, char Operation, int M, int i) {
        if (Operation == '+') {
            for (int j = 0; j < M; j++) needs[j] += special[i][j];
        } else {
            for (int j = 0; j < M; j++) needs[j] -= special[i][j];
        }
    }
    bool ValidOffer(vector<int>& needs, vector<vector<int>>& special, int M, int i) {
        for (int j = 0; j < M; j++) {
            if (needs[j] < special[i][j]) return false;
        }
        return true;
    }
};