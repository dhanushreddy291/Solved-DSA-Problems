class Solution {
private:
    void makeFreqMap(string &S, vector <int> &Map, int Size) {
        for (int i = 0; i < Size; i++) {
            int temp = (S[i] - 'a');
            Map[temp]++;
        }
        return;
    }
    bool checkIfContainsPermutation(string &S, int Size, int Index, vector <int> &Map) {
        if (Index < Size) {
            int temp = (S[Index] - 'a');
            if (Map[temp] > 0) {
                Map[temp]--;
                bool containsAtleastOne = false;
                for (int i = 0; i < 26; i++) {
                    if (Map[i] > 0) {
                        containsAtleastOne = true;
                        break;
                    };
                }
                if (!containsAtleastOne) return true;
                if(checkIfContainsPermutation(S, Size, Index + 1, Map)) return true;
                Map[temp]++;
            }
            return false;
        }
        for (int i = 0; i < 26; i++) {
            if (Map[i] > 0) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int M = s1.size(), N = s2.size();
        if (M == 1) {
            for (int i = 0; i < N; i++) {
                if (s2[i] == s1[0]) return true;
            }
            return false;
        }
        vector <int> Map (26, 0);
        makeFreqMap(s1, Map, M);
        for (int i = 0; i < N; i++) {
            int temp = (s2[i] - 'a');
            if (Map[temp] > 0) {
                Map[temp]--;
                if (checkIfContainsPermutation(s2, N, i + 1, Map)) return true;
                Map[temp]++;
            }
        }
        return false;
    }
};