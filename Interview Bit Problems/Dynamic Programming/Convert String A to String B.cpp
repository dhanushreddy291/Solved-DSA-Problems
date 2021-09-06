#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int minDistance(string A, string B);
};

int Solution::minDistance(string A, string B) {

    string tempA = "#" + A, tempB = "#" + B;
    int Data[A.size() + 1][B.size() + 1];

    for (int i = 0; i <= A.size(); i++)
    for (int j = 0; j <= B.size(); j++)
    {
        if (i == 0 || j == 0)
            Data[i][j] = i + j;

        else if (tempA[i] == tempB[j])
            Data[i][j] = Data[i - 1][j - 1];

        else
            Data[i][j] = min(1 + Data[i][j - 1], min (1 + Data[i - 1][j], 1 + Data[i - 1][j - 1]));
    }

    return Data[A.size()][B.size()];
}

int main()
{

    return 0;
}