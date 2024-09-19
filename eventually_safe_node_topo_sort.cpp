    //{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// Using topo sort to find the evential safenodes
// The node which ends up with a terminal node is called a safe node;

// Algo :
// Reverse the order of the adjacentcy list 
// find the indegree of each node 
// apply basic topo sort where the nodes with indegree 0 push into ans 

// Time Compx:
// Time - O(V+E)
// Space - O(V)

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
       vector<int> adjRev[V];
       int indegree[V] = {0};
       for(int i=0;i<V;i++){
           for(auto it: adj[i]){
               adjRev[it].push_back(i);
               indegree[i]++;
           }
       }
       
       queue<int> q;
       for(int i=0;i<V;i++){
           if(indegree[i] == 0){
               q.push(i);
           }
       }
       
       vector<int> ans;
       while(!q.empty()){
           int node = q.front();
           q.pop();
           ans.push_back(node);
           for(auto it: adjRev[node]){
               indegree[it]--;
               if(indegree[it] ==0) q.push(it);
           }
       }
       
       sort(ans.begin(), ans.end());
       return ans;
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