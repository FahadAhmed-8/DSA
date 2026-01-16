#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool f(int x, vector<int>& nums, int m, int k){
        int cnt = 0;
        int cntm = 0;
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] <= x){
                cnt++;
                if (cnt == k){
                    cntm++;
                    cnt = 0;
                }
            }else {
                cnt = 0; 
            }
        }
        return cntm >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        // Cast m to long long to prevent integer overflow during multiplication
        if ((long long)m * k > bloomDay.size()) return ans;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end()); 
        int high = *max_element(bloomDay.begin(), bloomDay.end()); 
        
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (f(mid, bloomDay, m, k)){
                ans = mid;
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    cout << s.minDays(bloomDay, m, k) << endl;

    return 0;
}