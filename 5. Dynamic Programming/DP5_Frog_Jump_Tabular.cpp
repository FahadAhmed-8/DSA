#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        // 1. Create a DP table to store the min cost to reach each stair
        // Size n is enough for indices 0 to n-1
        vector<int> dp(n, 0);
        
        // 2. Base Case: The cost to reach the first stair (index 0) is 0
        dp[0] = 0;
        
        // 3. Iteratively fill the DP table
        for (int ind = 1; ind < n; ind++) {
            
            // Option 1: Jump from the previous stair
            int left = dp[ind - 1] + abs(height[ind] - height[ind - 1]);
            
            // Option 2: Jump from two stairs back (only if ind > 1)
            int right = INT_MAX;
            if (ind > 1) {
                right = dp[ind - 2] + abs(height[ind] - height[ind - 2]);
            }
            
            // Store the minimum of the two choices
            dp[ind] = min(left, right);
        }
        
        // 4. The answer is the cost to reach the last stair (n-1)
        return dp[n - 1];
    }
};

int main() {
    Solution sol;
    vector<int> heights = {10, 30, 40, 20};
    
    cout << "Minimum cost (Tabulation): " << sol.minCost(heights) << endl;
    
    return 0;
}