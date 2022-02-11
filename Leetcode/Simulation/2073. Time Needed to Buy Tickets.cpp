class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        if (tickets[k] == 1) return k == 0 ? 1 : k + 1;
        int N = tickets.size(), time = 0;
        for (int i = 0; i < N; i++) {
            if (i < k) {
                time += min(tickets[i], tickets[k]);
            }
            else if (i > k) {
                time += min(tickets[i], tickets[k] - 1);
            }
        }
        return time + tickets[k];
    }
};