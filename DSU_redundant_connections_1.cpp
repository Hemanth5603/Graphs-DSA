#include<bits/stdc++.h>

using namespace std;

class DisjointSet{
    vector<int> parent, size;
    public: 

    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int node){
        if(node == parent[node]) return node;

        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int up_u = findUParent(u);
        int up_v = findUParent(v);
        if(up_u == up_v) return;
        if(size[up_u] < size[up_v]){
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }else{
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        int n = edges.size();
        DisjointSet dst(n);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            if(dst.findUParent(u) == dst.findUParent(v)){
                ans.push_back(it);
            }
            dst.unionBySize(u, v);
        }

        return ans.back();
    }
};