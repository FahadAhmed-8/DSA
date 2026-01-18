#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solve(int ind, int k, vector<int>& heights, vector<int>& dp) {
        if (ind == 0) return 0;
        if (dp[ind] != -1) return dp[ind];
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (ind - j >= 0) {
                int jumpCost = solve(ind - j, k, heights, dp) + abs(heights[ind] - heights[ind - j]);                
                minSteps = min(minSteps, jumpCost);
            }
        }
        return dp[ind] = minSteps;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        if (n == 0) return 0;
        vector<int> dp(n, -1);
        return solve(n - 1, k, heights, dp);
    } 
};

int main() {
    Solution sol;
    
    // Example test case
    vector<int> heights = {10, 30, 40, 50, 20};
    int k = 3;
    
    cout << "Minimum cost to reach the last stair (K=" << k << "): " 
         << sol.frogJump(heights, k) << endl;
         
    return 0;
}