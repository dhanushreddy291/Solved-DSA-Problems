class Solution {
private:
    pair <int, int> helper(int n) {
        int sum = 0, product = 1;
        if (n == 0) return {0, 0};
        while (n) {
            sum += n % 10;
            product *= n % 10;
            n /= 10;
        }
        return {sum, product};
    }
public:
    int subtractProductAndSum(int n) {
        pair <int, int> SumProduct = helper(n);
        return SumProduct.second - SumProduct.first;
    }
};