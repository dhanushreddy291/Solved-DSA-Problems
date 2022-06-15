class Solution {
private:
    static bool Comparator(const string& s1, const string& s2)
    {
        if (s1.size() != s2.size())
            return s1.size() < s2.size();
        else
            return s1 < s2;
    }

    int helperChain(string& s, int start, int end, vector<string>& words,
        vector<int>& chainLength)
    {
        int N = s.size(), i = 0, maxLength = 1;
        for (int j = start; j <= end; j++) {
            int k = 0, misMatch = 0, M = words[j].size(), i = 0;
            while (i < N && misMatch < 2 && k < M) {
                if (words[j][k] == s[i]) {
                    i++;
                    k++;
                }
                else {
                    misMatch++;
                    i++;
                }
            }
            if (i < N)
                misMatch++;
            if (misMatch < 2)
                maxLength = max(maxLength, 1 + chainLength[j]);
        }
        return maxLength;
    }

public:
    int longestStrChain(vector<string>& words)
    {
        int N = words.size();
        vector<int> chainLength(N, 1);
        sort(words.begin(), words.end(), Comparator);
        int maxSize = words[N - 1].size(), minSize = words[0].size();
        pair<int, int> temp = { -1, -1 };
        vector<pair<int, int> > Sizes(maxSize - minSize + 1, temp);
        for (int i = 0; i < N; i++) {
            int M = words[i].size();
            if (Sizes[M - minSize].first == -1)
                Sizes[M - minSize] = { i, i };
            else
                Sizes[M - minSize].second = i;
        }
        for (int i = 0; i < N; i++) {
            int M = words[i].size();
            if (M == minSize)
                continue;
            if (Sizes[M - minSize - 1].first != -1) {
                chainLength[i] = helperChain(
                    words[i], Sizes[M - minSize - 1].first,
                    Sizes[M - minSize - 1].second, words, chainLength
                );
            }
        }
        return *max_element(chainLength.begin(), chainLength.end());
    }
};