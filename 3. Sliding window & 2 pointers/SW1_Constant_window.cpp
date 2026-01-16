//max sum with k concecutive elements
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) return -1; 
        
        long long currsum = 0;
        long long maxsum = LLONG_MIN;
        int left = 0, right = 0;
        
        while (right < n){
            currsum += arr[right];
            
            if (right - left + 1 < k){
                right++;
            }
            else if (right - left + 1 == k){
                maxsum = max(maxsum, currsum);
                currsum -= arr[left];
                left++;
                right++;
            }
        }
        return (int)maxsum;
    }
};

int main() {
    vector<int> arr = {100, 200, 300, 400};
    int k = 2;

    Solution sol;
    int result = sol.maxSubarraySum(arr, k);

    cout << result << endl;

    return 0;
}