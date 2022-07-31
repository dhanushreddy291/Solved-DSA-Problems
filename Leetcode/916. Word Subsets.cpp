class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        int N = words1.size(), M = words2.size();
        vector <int> Freq(26, 0);
        vector <string> universalSubsets;

        for (int i = 0; i < M; i++) {

            int length = words2[i].size();
            vector <int> singleStringFreq(26, 0);

            for (int j = 0; j < length; j++) {
                singleStringFreq[words2[i][j] - 'a']++;
            }

            for (int j = 0; j < 26; j++) {
                Freq[j] = max(Freq[j], singleStringFreq[j]);
            }
            
            singleStringFreq.clear();
        }

        for (int i = 0; i < N; i++) {

            bool universalSubset = true;
            int length = words1[i].size();
            vector <int> singleStringFreq(26, 0);

            for (int j = 0; j < length; j++) {
                singleStringFreq[words1[i][j] - 'a']++;
            }

            for (int j = 0; j < 26; j++) {
                if (singleStringFreq[j] < Freq[j]) {
                    universalSubset = false;
                    break;
                }
            }

            if (universalSubset) {
                universalSubsets.push_back(words1[i]);
            }
            
            singleStringFreq.clear();

        }

        return universalSubsets;
    }
};