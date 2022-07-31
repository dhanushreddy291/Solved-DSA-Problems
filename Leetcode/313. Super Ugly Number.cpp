class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector <int> uglyNum = {1};
        int m = primes.size();
        vector <int> pointer(m, 0);
        priority_queue <pair <long, int>, vector<pair <long, int>>, greater<pair <long, int>>> Heap;
        for (int j = 0; j < m; j++) {
            Heap.push({primes[j], j});
        }
        for (int i = 1; i < n; i++) {
            pair <long, int> Top = Heap.top();
            Heap.pop();
            uglyNum.push_back(Top.first);
            pointer[Top.second]++;
            Heap.push({(long)primes[Top.second] * uglyNum[pointer[Top.second]], Top.second});
            while (Heap.top().first == Top.first) {
                pair <long, int> anotherTop = Heap.top();
                Heap.pop();
                pointer[anotherTop.second]++;
                Heap.push({(long)primes[anotherTop.second] * uglyNum[pointer[anotherTop.second]], anotherTop.second});
            }
        }
        return uglyNum[n - 1];
    }
};

