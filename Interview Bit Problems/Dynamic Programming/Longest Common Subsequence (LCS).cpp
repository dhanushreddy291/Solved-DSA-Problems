#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int solve(string A, string B);
};


int Solution::solve(string A, string B) {

    string tempA = "#" + A, tempB = "#" + B;
    int Data[A.size() + 1][B.size() + 1];

    for (int i = 0; i <= A.size(); i++)
    for (int j = 0; j <= B.size(); j++)
    Data[i][j] = (i * j == 0) ? 0 : (tempA[i] == tempB[j]) ? Data[i - 1][j - 1] + 1 :  max (Data[i - 1][j], Data[i][j - 1]);

    return Data[A.size()][B.size()];
}

int main()
{

    return 0;
}