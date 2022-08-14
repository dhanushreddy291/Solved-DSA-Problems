//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        for (int i = N - 2; i >= 0; i--) {
            for (int j = 0; j < N; j++) {
                int a = Matrix[i + 1][j];
                if (j < N - 1) a = max(a, Matrix[i + 1][j + 1]);
                if (j > 0) a = max(a, Matrix[i + 1][j - 1]);
                Matrix[i][j] += a;
            }
        }
        return *max_element(Matrix[0].begin(), Matrix[0].end());
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends