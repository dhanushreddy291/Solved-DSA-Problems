class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int N = strs.size();
        unordered_map <vector <int>, vector <int>> Map;
        vector <vector <string>> Anagrams;
        for (int i = 0; i < N; i++) {
            vector <int> Freq(26, 0);
            int M = strs[i].size();
            for (int j = 0; j < M; j++) {
                Freq[strs[i][j] - 'a']++;
            }
            Map[freq].push_back(i);
        }
        for (auto it = Map.begin(), it != Map.end(), it++) {
            int N = it->second.size();
            vector <string> Group;
            for (int i = 0; i < N; i++) {
                Group.push_back(strs[it->second[i]]);
            }
            if (N > 0) {
                Anagrams.push_back(Group);
            }
        }
        return Anagrams;
    }
};