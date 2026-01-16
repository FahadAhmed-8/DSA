#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long f(int k, vector<int>& piles){
        long long cnt = 0;
        for (int i = 0; i < piles.size(); i++){
            if (piles[i] <= k) cnt++;
            else {
                cnt += (piles[i] + k - 1) / k;
            }  
        }
        return cnt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = -1;
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        if (piles.size() > h) return -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if (f(mid, piles) <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    
    cout << s.minEatingSpeed(piles, h) << endl;
    
    return 0;
}