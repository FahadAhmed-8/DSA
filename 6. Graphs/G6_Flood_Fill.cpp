#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int sr, int sc, int color, int orgcolor,
             vector<vector<int>>& ans, int m, int n) {

        ans[sr][sc] = color;

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];

            if (nrow >= 0 && nrow < m &&
                ncol >= 0 && ncol < n &&
                ans[nrow][ncol] == orgcolor) {

                dfs(nrow, ncol, color, orgcolor, ans, m, n);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int orgcolor = image[sr][sc];

        if (orgcolor == color) return image;

        vector<vector<int>> ans = image;

        dfs(sr, sc, color, orgcolor, ans, m, n);

        return ans;
    }
};