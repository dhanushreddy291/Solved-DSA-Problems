//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int N){
        vector <long long> DP(N + 1);
        for (int i = 1; i <= N; i++) {
            DP[i] = i;
            for (int j = i - 3; j >= 1; j--) {
                DP[i] = max(DP[i], DP[j] * (i - j - 1));
            }
        }
        return DP[N];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends