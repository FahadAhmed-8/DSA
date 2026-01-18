#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // --- Option 1: Your Memoization (Top-Down) Approach ---
    int climb(int n, vector<int>& dp) {
        if (n == 0) return 1; // Base case: reached the top
        if (n < 0)  return 0; // Base case: overshot the steps
        
        if (dp[n] != -1) return dp[n];
        
        return dp[n] = climb(n - 1, dp) + climb(n - 2, dp);
    }

    // --- Option 2: Space-Optimized Tabulation (Bottom-Up) ---
    int climbStairsOptimized(int n) {
        if (n <= 1) return 1;
        
        int prev2 = 1; // Ways to reach step 0
        int prev1 = 1; // Ways to reach step 1
        int current;
        
        for (int i = 2; i <= n; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return climb(n, dp);
    }
};

int main() {
    Solution sol;
    int steps = 5;
    cout << "Ways to climb " << steps << " stairs: " << sol.climbStairs(steps) << endl;
    return 0;
}