#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int l = 0;
        int h = arr.size() - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (arr[mid] == target) return true;

            // Handle duplicates: if edges and mid are the same, we can't tell which side is sorted
            if (arr[l] == arr[mid] && arr[mid] == arr[h]) {
                l++;
                h--;
                continue;
            }

            // Left side is sorted
            if (arr[l] <= arr[mid]) {
                if (arr[l] <= target && target <= arr[mid]) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            } 
            // Right side is sorted
            else {
                if (arr[mid] <= target && target <= arr[h]) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Example with duplicates
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    if (sol.search(nums, target)) {
        cout << "Target " << target << " found in the array." << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    // Example where duplicates hide the sorted side
    vector<int> nums2 = {1, 0, 1, 1, 1};
    int target2 = 0;

    if (sol.search(nums2, target2)) {
        cout << "Target " << target2 << " found in the array." << endl;
    } else {
        cout << "Target " << target2 << " not found." << endl;
    }

    return 0;
}