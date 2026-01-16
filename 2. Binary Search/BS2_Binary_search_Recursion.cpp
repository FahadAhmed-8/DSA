#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bs(int l, int h, int k, vector<int>& nums) {
        if (l > h) return -1;
        
        int mid = l + (h - l) / 2;
        
        if (nums[mid] == k) {
            return mid;
        } 
        else if (nums[mid] > k) {
            return bs(l, mid - 1, k, nums);
        } 
        else {
            return bs(mid + 1, h, k, nums);
        }
    }

    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        return bs(0, nums.size() - 1, target, nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    
    cout << "Index: " << sol.search(nums, target) << endl;
    
    return 0;
}