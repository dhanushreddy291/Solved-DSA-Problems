#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int countMinSquares(int A);
};

int Solution::countMinSquares(int A) {
    vector <int> Squares;
    for (int i = 0, t = sqrt(i); i <= A; i++, t = sqrt(i)) {
        Squares.push_back(i);
        if (t * t == A) 
            Squares[A] = 1;
        else for (int j = 1; j * j <= i; j++)
            Squares[i] = min (Squares[i], 1 + Squares[i - j * j]);
    }
    return Squares[A];        
}


int main()
{

    return 0;
}
