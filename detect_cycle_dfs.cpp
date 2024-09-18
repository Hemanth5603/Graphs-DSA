#include <bits/stdc++.h> 
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis,int dis, int &maxi){
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, pathVis, dis+1, maxi);
        }else if(pathVis[it] == 1){
            maxi = max(maxi, dis);
        }
    }
    pathVis[node] = -1;
}


int findLongestCycle(vector<int> &arr)
{
    int n = arr.size();

    vector<int> adj[n+1];

    for(int i = 0;i<n;i++){
        if(arr[i] != -1){
            int u = i;
            int v = arr[i];
            adj[v].push_back(u);
        }
    }

    vector<int> vis(n+1, 0);
    vector<int> pathVis(n+1, -1);
    int maxi = -1;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj, vis, pathVis, 1, maxi);
        }
    }
    return maxi;

}
