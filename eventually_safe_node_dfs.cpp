//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    bool dfsCheck(int node, int vis[], int pathVis[], vector<int> adj[], int check[]){
            vis[node] = 1;  
            pathVis[node] = 1;
            check[node] = 0;
            for(auto it: adj[node]){
                if(!vis[it]){
                    check[node] = 0;
                    if(dfsCheck(it, vis, pathVis, adj, check) == true) return true;
                }
                else if(pathVis[it]){
                    check[node] = 0;
                    return true;
                }
            }
            check[node] = 1;
            pathVis[node] = 0;
            return false;
        }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        vector<int> safeNodes;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsCheck(i, vis, pathVis, adj, check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends