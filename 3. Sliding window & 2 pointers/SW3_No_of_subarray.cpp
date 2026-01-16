#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int number_of_subarray(vector<int>& arr, int k) {
        int countK = countAtMost(arr, k);
        int countKMinus1 = countAtMost(arr, k - 1);
        return countK - countKMinus1;
    }
    int countAtMost(vector<int>& arr, int target) {
        if (target < 0) return 0;
        int n = arr.size();
        int cnt = 0;
        long long currsum = 0;
        int left = 0, right = 0;
        while (right < n) {
            currsum += arr[right];
            while (currsum > target) {
                currsum -= arr[left];
                left++;
            }
            cnt += (right - left + 1);
            right++;
        }
        return cnt;
    }
};
int main() {
    vector<int> arr = {100, 200, 300, 400};
    int k = 300;
    Solution sol;
    int result = sol.number_of_subarray(arr, k);
    cout << result << endl;
    return 0;
}