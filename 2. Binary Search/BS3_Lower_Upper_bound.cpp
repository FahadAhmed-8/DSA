#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int l = 0;
        int h = arr.size() - 1;
        int ans = arr.size();
        
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (arr[m] >= target) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>& arr, int target) {
        int l = 0;
        int h = arr.size() - 1;
        int ans = arr.size();
        
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (arr[m] > target) {
                ans = m;
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
    vector<int> nums = {1, 2, 4, 4, 4, 6, 7};
    int target = 4;

    int lb = sol.lowerBound(nums, target);
    int ub = sol.upperBound(nums, target);

    cout << "Lower Bound index: " << lb << endl;
    cout << "Upper Bound index: " << ub << endl;
    cout << "Frequency of target: " << ub - lb << endl;

    return 0;
}