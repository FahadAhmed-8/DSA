#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int x = subArraySum(nums, goal);
        int y = subArraySum(nums, goal - 1);

        return x - y;
    }

    int subArraySum(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int cnt = 0;
        int left = 0;
        int right = 0;
        int currsum = 0;
        int n = nums.size();
        while (right < n) {
            currsum += nums[right];
            while (currsum > k) {
                currsum -= nums[left];
                left++;
            }
            if (currsum <= k) {
                cnt += (right - left + 1);
            }
            right++;
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << sol.numSubarraysWithSum(nums, goal) << endl;
    return 0;
}