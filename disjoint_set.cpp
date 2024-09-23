#include<bits/stdc++.h>
using namespace std;


// Disjoint Set is a data structure used in dynamic changing graph\
// It is used to find out if any two components are connected to eachother in constant time


// The disjoint set data structure generally provides two types of functionalities:

// Finding the parent for a particular node (findPar())
// Union (in broad terms this method basically adds an edge between two nodes)
// -  Union by rank
// -  Union by size


// Algorithm - 
// - Initially we configure two arrays
// - rank Array
// - parent Array 

// Firstly, the Union function requires two nodes(let’s say u and v) as arguments. Then we will find the ultimate parent (using the findPar() 
// function that is discussed later) of u and v. Let’s consider the ultimate parent of u is pu and the ultimate parent of v is pv.
// After that, we will find the rank of pu and pv.
// Finally, we will connect the ultimate parent with a smaller rank to the other 
// ultimate parent with a larger rank. But if the ranks are equal, 
// we can connect any parent to the other parent and we will increase the rank by one for the parent node to whom we have connected the other one.

// Path Compression is the techbique to remove the recusive process of finding the parent of the node



// Time Complexity - O(4 alpha) ~ O(1)

class DisjointSet{
    vector<int> rank, parent, size;
public:
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



    // if ranl is small of a node then attech the bigger componet to the smaller component
    // Increase the size of the larger component to the size of the smaller component
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


