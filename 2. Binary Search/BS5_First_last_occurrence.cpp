#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!binary_search(nums.begin(), nums.end(), target)) {
            return {-1, -1};
        }

        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        return {lb, ub - 1};
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    
    vector<int> result = sol.searchRange(nums, target);
    
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}