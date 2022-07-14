class Solution {

private:
    void findPermutations(int i, int N, unordered_map <int, int> &Map, vector <vector <int>> &permutations, vector <int> &permutation) {
        if (i == N) permutations.push_back(permutation);
        else {
            for (auto &it: Map) {
                if (it.second > 0) {
                    it.second--;
                    permutation.push_back(it.first);
                    findPermutations(i + 1, N, Map, permutations, permutation);
                    it.second++;
                    permutation.pop_back();
                }
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int N = nums.size();
        unordered_map <int, int> Map;
        for (int i = 0; i < N; i++) {
            Map[nums[i]]++;
        }
        vector <int> currPermutation;
        vector <vector <int>> permutations;
        findPermutations(0, N, Map, permutations, currPermutation);
        return permutations;
    }
    
};