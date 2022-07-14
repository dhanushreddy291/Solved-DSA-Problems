class Solution {
private:
    void merge(int start1, int end1, int end2, vector <int> &nums, vector <int> &inversions, vector <int> &index) {
        vector <int> L, R;
        for (int i = start1; i <= end1; i++) {
            L.push_back(index[i]);
        }
        for (int i = end1 + 1; i <= end2; i++) {
            R.push_back(index[i]);
        }
        int l = 0, r = 0, CS = 0, k = start1, lSize = end1 - start1 + 1, rSize = end2 - end1;
            while (l < lSize && r < rSize) {
                if (nums[L[l]] <= nums[R[r]]) {
                    inversions[L[l]] += CS;
                    index[k++] = L[l++];
                } else {
                    CS++;
                    index[k++] = R[r++];
                }
            }
        while (l < lSize) {
            inversions[L[l]] += CS;   
            index[k++] = L[l++];
        }
        while (r < rSize) index[k++] = R[r++];
        return;
    }

    void mergeSort(int start, int end, vector <int> &nums, vector <int> &inversions, vector <int> &index) {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        mergeSort(start, mid, nums, inversions, index);
        mergeSort(mid + 1, end, nums, inversions, index);
        merge(start, mid, end, nums, inversions, index);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector <int> inversions(N, 0);
        vector <int> index;
        for (int i = 0; i < N; i++) {
            index.push_back(i);
        }
        mergeSort(0, N - 1, nums, inversions, index);
        return inversions;
    }
};