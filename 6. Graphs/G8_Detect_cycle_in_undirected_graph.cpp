#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool bfs(int src, vector<int>& vis, vector<vector<int>>& adj) {
        queue<pair<int, int>> q;
        q.push({src, -1});
        vis[src] = 1;
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (int n : adj[node]){
                if(!vis[n]){
                    q.push({n, node});
                    vis[n] = 1;
                }
                else if (n != parent){
                    return true;
                }
            }
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {                   
                if (bfs(i, vis, adj)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};