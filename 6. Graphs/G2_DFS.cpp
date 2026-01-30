#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void using_dfs(int node, vector<bool>& vis, vector<int>& ans, vector<vector<int>>& adj){
        vis[node] = true;
        ans.push_back(node);
        
        for (int i : adj[node]){
            if (!vis[i]){
                using_dfs(i, vis, ans, adj);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<int> ans;
        vector<bool> vis(V, false);
        using_dfs(0, vis, ans, adj);
        return ans;
    }
};