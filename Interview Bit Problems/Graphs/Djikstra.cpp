#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  vector<int> solve(int A, vector<vector<int> > &B, int C) {};
};

vector<int> Solution::solve(int A, vector<vector<int> > &B, int C) {
  
  priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> Heap;
  vector <pair <int, int>> Adj[A];
  vector <int> Distance (A, INT_MAX);
  Distance[C] = 0;
  
  for (int i = 0; i < B.size(); i++) {
    Adj[B[i][0]].push_back({B[i][2], B[i][1]});
    Adj[B[i][1]].push_back({B[i][2], B[i][0]});
  }

  for (int i = 0; i < Adj[C].size(); i++)
    Heap.push(Adj[C][i]);

  while (!Heap.empty()) {
    int Weight = Heap.top().first, Node = Heap.top().second;
    Heap.pop();
    if (Distance[Node] > Weight) {
      Distance[Node] = Weight;
      for (int i = 0; i < Adj[Node].size(); i++) {
        if (Distance[Adj[Node][i].second] > Weight + Adj[Node][i].first) {
          Distance[Adj[Node][i].second] = Weight + Adj[Node][i].first;
          Heap.push({Distance[Adj[Node][i].second], Adj[Node][i].second});
        }
      }
    }
  }

  return Distance;  

}


int main()
{

  return 0;
}