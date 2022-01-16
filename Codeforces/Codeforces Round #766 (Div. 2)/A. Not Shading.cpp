#include <bits/stdc++.h>
using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int NumberofTestCases, N, M, R, C;
	cin >> NumberofTestCases;

	while (NumberofTestCases--)
	{
		cin >> N >> M >> R >> C;
		vector<bool> Rows(N, false), Columns(M, false);
		vector<vector < bool>> Grid(N, vector<bool> (M, false));
		char Color;
		bool AtleastOneBlackPresent = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> Color;
				if (Color == 'B')
				{
					Grid[i][j] = true;
					AtleastOneBlackPresent = true;
					Rows[i] = true;
					Columns[j] = true;
				}
			}
		}
		if (AtleastOneBlackPresent)
		{
			if (Grid[R - 1][C - 1]) cout << "0\n";
			else if (Rows[R - 1] || Columns[C - 1]) cout << "1\n";
			else cout << "2\n";
		}
		else cout << "-1\n";
	}
}