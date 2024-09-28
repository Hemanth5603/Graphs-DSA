//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// path which has has all the vertices connected

class Solution
{
    public:
    
    bool dfs(int node, int count, unordered_map<int,list<int>>& adj, vector<int> visited) {
        if(count == (visited.size()-1)) return true;
        visited[node] = 1;
        count++;
        for(auto it: adj[node]) {
            if(!visited[it]) {
                if(dfs(it,count,adj,visited)) return true;
            }
        }
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<M;i++) {
            int u = Edges[i][0];
            int v = Edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=1;
        vector<int>visited(N+1,0);
        for(int i=1;i<=N;i++) {
            if(dfs(i,count,adj,visited)) return true;
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends