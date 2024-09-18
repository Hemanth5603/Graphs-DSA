//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> des) {
                         
        if(src.first == des.first && src.second == des.second) return 0;                 
       queue<pair<int, pair<int, int>>> q;
       
       int n = grid.size();
       int m = grid[0].size();
       
       vector<vector<int>> dist(n , vector<int>(m , 1e9));
       dist[src.first][src.second] =  0;
       q.push({0, {src.first, src.second}});
       int drow[] = {-1,0,1,0};
       int dcol[] = {0,1,0,-1};
      
        
        while(!q.empty()){
           auto it = q.front();
           q.pop();
           int dis = it.first;
           int r = it.second.first;
           int c = it.second.second;
           for(int i = 0;i<4;i++){
               int nrow = r + drow[i];
               int ncol = c + dcol[i];
               if(nrow >= 0 && nrow <n && ncol>=0 && ncol < m && 
                grid[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = 1 + dis;
                    if(nrow == des.first && ncol == des.second){
                        return dis +1;
                    }
                    q.push({1 + dis,{nrow, ncol}});
                }
           }
           
       }
       
       return -1;
       
       
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends