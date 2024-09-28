//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int drow[8] = {-2,-1,1,2,2,1,-1,-2};
    int dcol[8] = {1,2,2,1,-1,-2,-2,-1};
    
    int bfs(int r, int c, int trow, int tcol, vector<vector<int>> &vis, int n){
        vis[r][c] = 1;
        if(r == trow && c == tcol) return 0;
        queue<pair<pair<int,int>, int>> q;
        int mini = 99999;
        q.push({{r, c},0});
            while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int cnt = q.front().second;
            q.pop();
            if(row == trow && col == tcol){
                mini = min(mini, cnt);
            }
            for(int i=0;i<8;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < n && !vis[nrow][ncol]){
                    q.push({{nrow, ncol}, cnt +1});
                    vis[nrow][ncol] = 1;
                    
                }
                
            }
            
        }
        return mini;
        
    }
    

	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n){
	    vector<vector<int>> vis(n, vector<int>(n, 0));

        int irow = KnightPos[0]-1;
        int icol = KnightPos[1]-1;
        int trow = TargetPos[0]-1;
        int tcol = TargetPos[1]-1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == irow && j == icol){
                    return bfs(irow, icol, trow, tcol, vis, n);
                }
            }
        }	    
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