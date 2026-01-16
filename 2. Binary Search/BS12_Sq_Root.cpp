#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        int low = 1;
        int high = x;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid <= x / mid) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    cout << sol.mySqrt(4) << endl;
    cout << sol.mySqrt(8) << endl;
    cout << sol.mySqrt(16) << endl;
    cout << sol.mySqrt(0) << endl;

    return 0;
}