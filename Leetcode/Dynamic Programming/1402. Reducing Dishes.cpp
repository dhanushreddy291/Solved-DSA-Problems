class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector <vector <int>> Map(501, vector <int> (501, -1));
        return FindMax(satisfaction, 0, satisfaction.size(), 1, Map);
    }
    int FindMax(vector <int> &satisfaction, int Start, int End, int Val, vector <vector <int>> &Map) {
        if (Start >= End) return 0;
        else if (Map[Start][Val] != -1) return Map[Start][Val];
        else if (satisfaction[Start] >= 0) {
            int Satisfaction = 0;
            for (int i = Start; i < End; i++, Val++) {
                Satisfaction += (Val * satisfaction[i]);
            }
            return Map[Start][Val] = Satisfaction;
        }
        else return Map[Start][Val] = max(satisfaction[Start] * Val + FindMax(satisfaction, Start + 1, End, Val + 1, Map), FindMax(satisfaction, Start + 1, End, Val, Map));
    }
};