#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    vector<int> testCase = {4, 5, 6, 7, 0, 1, 2};
    
    int result = sol.findMin(testCase);
    
    cout << "The minimum element in the array is: " << result << endl;

    return 0;
}