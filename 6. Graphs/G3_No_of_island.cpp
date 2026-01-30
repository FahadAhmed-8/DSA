#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while (!q.empty()){
            int n = q.front();
            q.pop();

            for(int itr = 0; itr < adj.size(); itr++){
                if (adj[n][itr] == 1 && !vis[itr]){
                    vis[itr] = 1;
                    q.push(itr);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        int cnt = 0;

        for (int i = 0; i < V; i++){
            if (!vis[i]){
                bfs(i, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
};