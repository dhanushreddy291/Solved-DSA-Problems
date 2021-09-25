class Solution {
public:
    void Reverse (vector <int> &A, int Start, int End) {
        for (int i = 0; i <= (End - Start) / 2; i++)
            swap (A[Start + i], A[End - i]);
    }
    void rotate(vector<int>& nums, int k) {
        Reverse (nums, 0, k - 1);
        Reverse (nums, k, nums.size() - 1);
        Reverse (nums, 0, nums.size() - 1);
    }
};

// -100 -1 99 3
// 3 99 -1 -100