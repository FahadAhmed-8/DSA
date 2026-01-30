#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node, vector<int>& temp, vector<int>& vis, vector<vector<int>>& adj){
        temp.push_back(node);
        vis[node] = 1;
         for (int i = 0; i < adj[node].size(); i++){
            if (!vis[adj[node][i]]){
                dfs(adj[node][i], temp, vis, adj);
            }
         }
         
    }
  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> ans;
        vector<int> vis(V, 0);
        
        vector<vector<int>> adj(V);
        
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for (int i = 0; i < V; i++){
            if (!vis[i]){
                vector<int> temp;
                dfs(i, temp, vis, adj);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
