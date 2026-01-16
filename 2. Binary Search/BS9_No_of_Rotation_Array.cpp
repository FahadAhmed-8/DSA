#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int ind = -1;
        int low = 0; 
        int high = nums.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if (nums[low] <= nums[high]) {
                if (nums[low] < ans) {
                    ans = nums[low];
                    ind = low;
                }
                break;
            }

            if (nums[low] <= nums[mid]){
                if (nums[low] <= ans){
                    ans = nums[low];
                    ind = low;
                }
                low = mid + 1;
            }
            else{
                if (nums[mid] <= ans){
                    ans = nums[mid];
                    ind = mid;
                }
                high = mid - 1;
            }
        }

        return ind;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int rotationCount = sol.findMin(nums);
    cout << rotationCount << endl;
    return 0;
}