#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        vector<int> bfs_result;
        vector<int> vis(V, 0);
        
        queue<int> q;
        q.push(0); 
        vis[0] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs_result.push_back(node);
            
            for (auto itr : adj[node]){
                if(!vis[itr]){
                    vis[itr] = 1;
                    q.push(itr);
                }
            }
        }
    }
};