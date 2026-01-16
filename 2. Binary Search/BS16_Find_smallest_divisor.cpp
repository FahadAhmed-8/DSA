#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long f(int x, vector<int>& nums){
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += (nums[i] + x - 1) / x;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (f(mid, nums) <= threshold){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    
    cout << s.smallestDivisor(nums, threshold) << endl;
    
    return 0;
}