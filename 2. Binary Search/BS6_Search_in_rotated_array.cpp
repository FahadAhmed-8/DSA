#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int l = 0;
        int h = arr.size() - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (arr[mid] == target) return mid;

            if (arr[l] <= arr[mid]) {
                if (arr[l] <= target && arr[mid] >= target) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (arr[mid] < target && arr[h] >= target) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    
    int result = sol.search(nums, target);
    
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}