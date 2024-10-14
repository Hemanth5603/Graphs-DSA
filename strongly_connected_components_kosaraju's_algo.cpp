//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// Algorighm - 
// apply dfs and traverse throuth the graph and store each node in stack.
// now reverse all the edges of the graph and make of copy of that .
// now apply dfs again on new reversed graph and count the individual components.

// Intution 
// reversing the edges will not effect the connected components 



class Solution
{
	public:
	   void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st){
	       vis[node] =1;
	       for(auto it: adj[node]){
	           if(!vis[it]){
	               dfs(it, vis, adj, st);
	           }
	       }
	       st.push(node);
	   }

	   void dfs3(int node, vector<int> &vis, vector<int> adj[]){
	       vis[node] =1;
	       for(auto it: adj[node]){
	           if(!vis[it]){
	               dfs3(it, vis, adj);
	           }
	       }
	   }
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> adjList[V];
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        vector<int> adjT[V];
        for(int i=0;i<V;i++){
            vis[i] = 0;
            for(auto it: adj[i]){
                
                adjT[it].push_back(i);
            }
        }
        
        int cnt = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                cnt++;
                dfs3(node, vis, adjT);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
