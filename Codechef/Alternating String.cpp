#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int NumberofTestCases, length;
    string Str;
    cin >> NumberofTestCases;

    while (NumberofTestCases--) {
        cin >> length;
        int one = 0, zero = 0;
        cin >> Str;
        for (char c : Str) {
            if (c == '0') zero++;
            else one++;
        }
        cout << ((abs(zero - one) < 2) ? length : (2 * min(zero, one) + 1)) << "\n";
    }

    return 0;
}