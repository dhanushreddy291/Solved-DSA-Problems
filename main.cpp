#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void Build(int index, int start, int end, vector < int > & Tree, vector < int > & A) {
      if (start == end)
        Tree[index] = A[start];

      else {
        int mid = start + (end - start) / 2,
          Left_Child = 2 * index + 1,
          Right_Child = Left_Child + 1;

        Build(Left_Child, start, mid, Tree, A);
        Build(Right_Child, mid + 1, end, Tree, A);

        Tree[index] = Tree[Left_Child] + Tree[Right_Child];
      }
    }

    int Query(int index, int start, int end, int L, int R, vector < int > & Tree) {
      // Non-Overlapping Case
      if (L > end || R < start)
        return 0;

      //  Complete Overlap
      if (L <= start && R >= end)
        return Tree[index];

      // Partial Overlap
      int mid = start + (end - start) / 2,
        Left_Child = 2 * index + 1,
        Right_Child = Left_Child + 1;

      return Query(Left_Child, start, mid, L, R, Tree) + Query(Right_Child, mid + 1, end, L, R, Tree);

    }

    void SieveofErastothens(int N, vector < bool > & isPrime) {
      for (int i = 2; i * i <= N; i++)
        if (isPrime[i])
          for (int j = 2 * i; j <= N; j += i)
            isPrime[j] = false;
    }

    void Update(int index, int start, int end, int UpdateLocation, int UpdateValue, vector < int > & Tree) {
      // We will not update the values at other locations
      if (UpdateLocation < start || UpdateLocation > end)
        return;

      // If the function comes here and start = end, it automatically implies that start = UpdateLocation = end
      if (start == end)
        Tree[index] += UpdateValue;

      // Updating Values in the Segment Tree only where it is needed using Recursion
      else {
        int mid = start + (end - start) / 2,
          Left_Child = 2 * index + 1,
          Right_Child = Left_Child + 1;

        Update(Left_Child, start, mid, UpdateLocation, UpdateValue, Tree);
        Update(Right_Child, mid + 1, end, UpdateLocation, UpdateValue, Tree);

        Tree[index] = Tree[Left_Child] + Tree[Right_Child];

      }
    }

    vector < int > solve(vector < int > & A, vector < string > & B, vector < int > & C, vector < int > & D) {

      vector < int > Answer;
      int N = INT_MIN;

      // For finding the maximum number till which we have to check if number is prime and storing the list of prime numbers    
      for (int i = 0; i < A.size(); i++)
        N = max(N, A[i]);

      for (int i = 0; i < D.size(); i++)
        N = max(N, D[i]);

      vector < bool > isPrime(N + 1, true);

      isPrime[0] = false;
      isPrime[1] = false;

      SieveofErastothens(N, isPrime);

      // Converting all the Numbers in A to either 0 or 1 depending on whether they are prime or not.    
      for (int i = 0; i < A.size(); i++)
        A[i] = (isPrime[A[i]]) ? 1 : 0;

      // Now the segment Tree contains Sub - Queries for the number of Primes in a given Range.
      vector < int > Tree(4 * A.size(), 0);
      Build(0, 0, A.size() - 1, Tree, A);

      for (int i = 0; i < B.size(); i++) {
        if (B[i][0] == 'A')
          Answer.push_back(Query(0, 0, A.size() - 1, C[i] - 1, D[i] - 1, Tree));

        else {
          // if the Number at given index C[i] in A is prime and D[i] is not prime    
          if (A[C[i] - 1] == 1 && !isPrime[D[i]]) {
            Update(0, 0, A.size() - 1, C[i] - 1, -1, Tree);
            A[C[i] - 1] = 0;
          }

          // if the Number at give index C[i] in A is not prime and D[i] is prime
          else if (A[C[i] - 1] == 0 && isPrime[D[i]]) {
            Update(0, 0, A.size() - 1, C[i] - 1, 1, Tree);
            A[C[i] - 1] = 1;
          }
        }
      }
      return Answer;
    }
};

int main()
{
    return 0;
}