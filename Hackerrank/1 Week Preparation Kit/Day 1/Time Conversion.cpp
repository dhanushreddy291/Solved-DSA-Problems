#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    if (s[8] == 'P') {
        int a = (s[1] - '0') + 10 * (s[0] - '0') + 12;
        if (a == 24) return s.substr(0, 8);
        s[0] = (a / 10 + '0');
        s[1] = (a % 10 + '0');
    } else if (s[8] == 'A' && 10 * (s[0] - '0') + (s[1] - '0') >= 12) {
        s[0] = s[1] = '0';
    } 
    return s.substr(0, 8);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
