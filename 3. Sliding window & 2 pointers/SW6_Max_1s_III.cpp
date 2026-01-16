#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int maxlens = 0;
        int n = nums.size();
        int zeros = 0;

        while (right < n) {
            if (nums[right] == 0) zeros++;
            
            if (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            else {
                maxlens = max(maxlens, right - left + 1);
            }
            right++;
        }
        return maxlens;
    }
};

int main() {
    Solution sol;
    
    // Test case
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    
    int result = sol.longestOnes(nums, k);
    
    cout << "Max length: " << result << endl; // Output should be 6
    
    return 0;
}
