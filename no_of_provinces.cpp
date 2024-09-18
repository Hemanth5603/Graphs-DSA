//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    
  private:
    void dfs(int node,vector<int> adjLs[],int vis[]){
        vis[node] = 1;
        for(auto it: adjLs[node]){
            if(!vis[it]){
                dfs(it,adjLs,vis);
            }
        }
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int n) {
        vector<int> adjLs[n];
        for(int i = 0;i<n;i++){ 
            for(int j=0;j<n;j++){
                if(adj[i][j] ==1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        int vis[n] = {0};
        int cnt  = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adjLs,vis);
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends