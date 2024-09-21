#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
        greater<pair<int,int>>>pq;
        
        vector<pair<int,int>> adj[n+1]; 
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        pq.push({k, 0});

        while(!pq.empty()){
            int node = pq.top().first;
            int time = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjTime = it.second;
                if(time + adjTime < dist[adjNode]){
                    dist[adjNode] = time + adjTime;
                    pq.push({adjNode, dist[adjNode]});
                }
            }
        }

        for(int i=1;i<=n;i++) if(dist[i] == 1e9) return -1;
        int maxi = INT_MIN;
        for(int i=1;i<=n;i++){
            maxi = max(dist[i], maxi);
        }
        return maxi;

    }
};