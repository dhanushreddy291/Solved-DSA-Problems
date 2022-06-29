class Comparator {
public:
    bool operator() (const pair <int, string> &A, const pair <int, string> &B) {
        if (A.first == B.first) return A.second.compare(B.second) > 0;
        return A.first < B.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string, int> Map;
        priority_queue <pair <int, string>, vector <pair <int, string>>, Comparator> Heap;
        vector <string> Frequent;
        for (string &word: words) Map[word]++;
        for (auto it = Map.begin(); it != Map.end(); it++) {
            Heap.push({it -> second, it -> first});
        }
        while (k--) {
            pair <int, string> word = Heap.top();
            Heap.pop();
            Frequent.push_back(word.second); 
        }
        return Frequent;
    }
};