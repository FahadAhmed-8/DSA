#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void permutation(int ind, vector<int>& freq, vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums) {
        // Base Case: If our current list size matches input size
        if (ind == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // If the element has not been used yet
            if (!freq[i]) {
                freq[i] = 1;                // Mark as visited
                curr.push_back(nums[i]);    // Pick the element
                
                // Recursive call
                permutation(ind + 1, freq, curr, ans, nums);
                
                // Backtrack (Undo the changes)
                curr.pop_back();            // Remove element
                freq[i] = 0;                // Mark as unvisited
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        int n = nums.size();
        
        vector<int> freq(n, 0);
        
        permutation(0, freq, curr, ans, nums);
        return ans;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {1, 2, 3};
    
    vector<vector<int>> result = sol.permute(nums);
    
    cout << "All Permutations:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}