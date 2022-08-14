class Solution {
public:
    int numTeams(vector<int>& rating) {
        int teams = 0, N = rating.size();
        for (int i = 0; i < N; i++) {
            int smallerOnLeft = 0, greaterOnLeft = 0, smallerOnRight = 0, greaterOnRight = 0;
            for (int j = 0; j < i; j++) {
                rating[j] < rating[i] ? smallerOnLeft++ : greaterOnLeft++;
            }
            for (int j = i + 1; j < N; j++) {
                rating[j] < rating[i] ? smallerOnRight++ : greaterOnRight++;
            }
            teams += smallerOnLeft * greaterOnRight + greaterOnLeft * smallerOnRight;
        }
        return teams;
    }
};