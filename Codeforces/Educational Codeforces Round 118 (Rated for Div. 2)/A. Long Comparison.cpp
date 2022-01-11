#include <bits/stdc++.h>
using namespace std;

int size(int a, int b) {
    int Size = b;
    while (a > 0) {
        a /= 10;
        Size++;
    }
    return Size;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int NumberofTestCases, x1, p1, x2, p2;
    cin >> NumberofTestCases;

    while (NumberofTestCases--) {

        cin >> x1 >> p1 >> x2 >> p2;
        int Size1 = size(x1, p1), Size2 = size(x2, p2), Difference = Size1 - Size2;
        
        if (Difference == 0) {
            if (p1 > p2) x2 /= pow(10, p1 - p2);
            else if (p1 < p2) x1 /= pow(10, p2 - p1);
            (x1 > x2) ? cout << ">\n" : (x1 == x2) ? cout << "=\n" : cout << "<\n";
        } 
        
        else
        (Difference > 0) ? cout << ">\n" : cout << "<\n";

    }

    return 0;
}