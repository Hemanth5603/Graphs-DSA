//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
 
 

class DisjointSet{
   
public:
 vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        // path compression below 
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_v] = rank[ulp_u];

        }else{
            parent[ulp_v] = rank[ulp_u];
            rank[ulp_u]++;

        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];

        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

 
class Solution {
  public:
     int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int cycle = 0;
        int components = 0;
        for(auto it: edge) { 
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)) { 
                cycle++;
            } 
            else { 
                ds.unionBySize(u, v);
            } 
        } 
        for(int i = 0; i <= n; i++) { 
            if(ds.parent[i] == i) { 
                components++;
            }
        } 
        
        if((components - 2) <= cycle) { 
            return (components - 2);
        } 
        else { 
            return -1;
        } 
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends