class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map <string, string> Map;
        for (vector<string> &str: paths) {
            Map[str[0]] = str[1];
        }
        while(true) {
            if (Map[paths[0][1]] != "")
            paths[0][1] = Map[paths[0][1]];
            else return paths[0][1];
        }
    }
};