#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>& adj,unordered_map<int,bool>& visited,vector<int>&ans,int node){
    ans.push_back(node);
    visited[node]=true;
    for(int i=0;i<adj[node].size();i++){
      if(!visited[adj[node][i]]) {
        dfs(adj, visited, ans, adj[node][i]);
      }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges){
    vector<vector<int>>adj(V);
     for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<vector<int>>ans;
    unordered_map<int,bool>visited;


   for(int i=0;i<V;i++){
       if(!visited[i]){
         vector<int>component;
           dfs(adj,visited,component, i);
           ans.push_back(component);
       }
   }


   return ans;
}