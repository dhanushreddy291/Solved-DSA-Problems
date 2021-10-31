class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set <string> Set;
        vector <string> TransformedAlphabet = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int N = words.size();
        for (int i = 0; i < N; i++) {
            string temp = "";
            int Size = words[i].size();
            for (int j = 0; j < Size; j++) {
                temp += TransformedAlphabet[words[i][j] - 'a'];
            }
            Set.insert(temp);
        }
        return Set.size();
    }
};