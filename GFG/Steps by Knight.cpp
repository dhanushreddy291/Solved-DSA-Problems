//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    private:
    bool validPos(int x, int y, int N) {
        return x < N && y < N && x >= 0 && y >= 0;
    }
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    KnightPos[0] -= 1;
	    KnightPos[1] -= 1;
	    TargetPos[0] -= 1;
	    TargetPos[1] -= 1;
	    queue <pair <int, int>> Queue;
	    Queue.push({KnightPos[0], KnightPos[1]});
        unordered_set <pair <int, int>> Map;
        int steps = 0, size = 1;
        Map[{KnightPos[0], KnightPos[1]}] = 0;
        if (TargetPos == KnightPos) return 0;
        vector <int> dx = {-1, -2, -2, -1, 1, 2, 2, 1}, dy = {-2, -1, 1, 2, 2, 1, -1, -2};
        while (!Queue.empty()) {
            while (size--) {
                pair <int, int> Pos = Queue.front();
                Queue.pop();
                for (int i = 0; i < 8; i++) {
                    if (!validPos(Pos.first + dx[i], Pos.second + dy[i], N)) continue;
                    if (Map.find({Pos.first + dx[i], Pos.second + dy[i]}) == Map.end()) {
                        if (Pos.first + dx[i] == TargetPos[0] && Pos.second + dy[i] == TargetPos[1]) {
                            return steps + 1;
                        }
                        Map.insert({Pos.first + dx[i], Pos.second + dy[i]});
                        Queue.push({Pos.first + dx[i], Pos.second + dy[i]});
                    }
                }
            }
            steps++;
            size = Queue.size();
        }
        return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends