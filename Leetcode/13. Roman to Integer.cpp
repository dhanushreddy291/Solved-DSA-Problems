class Solution {
public:
    int romanToInt(string s) {
            map <char, int> Map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
	int Answer = Map[s.back()], N = s.size();
	for (int i = N - 2; i >= 0; i--) {
		if (Map[s[i + 1]] > Map[s[i]]) Answer -= Map[s[i]];
		else Answer += Map[s[i]];
	}
	return Answer;
    }
};