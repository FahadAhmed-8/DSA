#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findFloor(vector<int>& arr, int target) {
        int l = 0;
        int h = arr.size() - 1;
        int ans = -1;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (arr[m] <= target) {
                ans = arr[m]; 
                l = m + 1;    
            } else {
                h = m - 1;
            }
        }
        return ans;
    }

    int findCeiling(vector<int>& arr, int target) {
        int l = 0;
        int h = arr.size() - 1;
        int ans = -1;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (arr[m] >= target) {
                ans = arr[m];
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 8, 10, 11, 12, 19};
    int target = 5;

    cout << "Floor of " << target << " is: " << sol.findFloor(nums, target) << endl;
    cout << "Ceiling of " << target << " is: " << sol.findCeiling(nums, target) << endl;

    return 0;
}