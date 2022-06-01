class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector <int> Answer = {0, 0, 0};
        for (vector <int> &triplet: triplets) {
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]){
                Answer[0] = max(Answer[0], triplet[0]);
                Answer[1] = max(Answer[1], triplet[1]);
                Answer[2] = max(Answer[2], triplet[2]);
            }
        }
        return target == Answer;
    }
};