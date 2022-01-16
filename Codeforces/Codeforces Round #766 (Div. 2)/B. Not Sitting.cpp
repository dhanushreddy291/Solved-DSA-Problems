#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int NumberofTestCases, N, M, temp;
	cin >> NumberofTestCases;

	while (NumberofTestCases--)
	{
		cin >> N >> M;
		int Product = N * M;
		priority_queue<int, vector < int>, greater < int>> Heap;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				Heap.push(max(max(i + j, N + M - i - j - 2), max(N - i - 1 + j, M - j - 1 + i)));
			}
		}
		while (Product--)
		{
			temp = Heap.top();
			Heap.pop();
			cout << temp << " ";
		}
		cout << "\n";
	}
}