#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int NumberofTestCases, N, V1, V2, maxDegree = 0;
	cin >> NumberofTestCases;

	while (NumberofTestCases--)
	{
        cin >> N;
        if (N > 4) {
            N--;
            while(N--) cin >> V1 >> V2;
            cout << "-1\n";
            continue;
        }
        vector <int> Degree(N, 0), Edge(N - 1, 0);
        for (int i = 1; i < N; i++) {
            cin >> V1 >> V2;
            Degree[V1 - 1]++;
            Degree[V2 - 1]++;
            Edge[i - 1] = V1 - 1;
            maxDegree = max(maxDegree, max(Degree[V1 - 1], Degree[V2 - 1]));
        }
        if (maxDegree > 2) cout << "-1\n";
        else if (N == 2) cout << "2\n";
        else if (N == 3) cout << "2 3\n";
        else {
            if (Degree[Edge[0]] == 2) {
                cout << "2 3 5\n";
            }
            else cout << "3 2 5\n";
        }
	}
}