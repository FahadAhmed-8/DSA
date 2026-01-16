#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return oddSubarray(nums, k) - oddSubarray(nums, k - 1);
    }

    int oddSubarray(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int cnt = 0;
        int left = 0, right = 0;
        int n = nums.size();
        int sum = 0;
        while (right < n) {
            sum += (nums[right] % 2);
            while (sum > k) {
                sum -= (nums[left] % 2);
                left++;
            }
            cnt += (right - left + 1);
            right++;
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << sol.numberOfSubarrays(nums, k) << endl;
    return 0;
}