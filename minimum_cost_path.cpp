//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    public:
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = grid[0][0];
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
           
            int cost = it.first;
            int row = it.second.first;
            int col = it.second.second;
           
            if(row == n-1 && col == n-1) return cost;
           
            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(ncol >= 0 && ncol < n && nrow >= 0 && nrow < n && dist[nrow][ncol] > cost + grid[nrow][ncol]) {
                    dist[nrow][ncol] = cost + grid[nrow][ncol];
                    pq.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends