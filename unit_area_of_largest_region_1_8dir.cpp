//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    int drow[8] = {-1,-1,0,1,1, 1, 0,-1};
    int dcol[8] = {0 , 1,1,1,0,-1,-1,-1};
    
    void bfs(int r, int c, int n, int m,int &cnt, vector<vector<int>> &vis, vector<vector<int>> &grid){
        queue<pair<int,int>> q;
        vis[r][c] = 1;
        q.push({r, c});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0;i<8;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];  
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    cnt++;
                    q.push({nrow, ncol});
                    vis[nrow][ncol] =1;
                }
            }
        }
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                int cnt = 1;
                if(grid[i][j] == 1 && !vis[i][j]){
                    bfs(i, j, n, m, cnt, vis, grid);
                    maxi = max(maxi,cnt);
                } 
            }
        }
        return maxi;
       
    }

};




//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends