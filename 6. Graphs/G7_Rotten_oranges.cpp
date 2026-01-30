#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<pair<int,int>, int>> q;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2){
                    q.push({{i, j}, 0});       
                }
            }
        }

        int time = 0;
        int delrow[4] = {0, 1, 0, -1};
        int delcol[4]= {-1, 0, 1, 0};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            time = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, time + 1});
                }
            }
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    return -1;    
                }
            }
        }

        return time;
    }
};