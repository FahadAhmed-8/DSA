#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    // Helper function for recursion with memoization
    int jump(int ind, vector<int>& dp, vector<int>& height) {
        // Base Case: If the frog is on the first stair, cost is 0
        if (ind == 0) return 0;
        
        // If we have already calculated the result for this index, return it
        if (dp[ind] != -1) return dp[ind];
        
        // Choice 1: Jump from the previous stair (i-1)
        int left = jump(ind - 1, dp, height) + abs(height[ind] - height[ind - 1]);
        
        // Choice 2: Jump from two stairs back (i-2)
        int right = INT_MAX;
        if (ind > 1) {
            right = jump(ind - 2, dp, height) + abs(height[ind] - height[ind - 2]);
        }
        
        // Store the result in the DP table and return the minimum of the two choices
        return dp[ind] = min(left, right);
    }
    
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        // Initialize DP table with -1
        vector<int> dp(n, -1); 
        
        // Start the process from the last index
        return jump(n - 1, dp, height);
    }
};

int main() {
    Solution obj;
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    cout << "Minimum cost: " << obj.minCost(heights) << endl;
    return 0;
}